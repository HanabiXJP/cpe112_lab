    //66070501038 Phanthach Jiamjaruschot
    #include <stdio.h>
    #include <stdlib.h>

    typedef int data_t;

    typedef struct edge_t edge_t;

    typedef struct vert_t // Vertex - Linked List
    {
        data_t data;
        struct edge_t *adj; // Adjacent Edges - Linked List
        struct vert_t *next;
    } vert_t;

    typedef struct edge_t // Edge - Linked List
    {
        int weight;
        vert_t *tVert; // Terminal Vertex
        struct edge_t *next;
    } edge_t;

    // Insert new vertex (Ignores duplicate)
    vert_t *insertVert(vert_t **root, data_t data)
    {
        vert_t *newVert = malloc(sizeof(vert_t));
        newVert->data = data;
        newVert->adj = NULL;
        newVert->next = NULL;

        if (*root == NULL || (*root)->data > data)
        {
            newVert->next = *root;
            *root = newVert;
            return newVert;
        }

        vert_t *pTemp = *root;
        while (pTemp->next != NULL && pTemp->next->data < data)
        {
            pTemp = pTemp->next;
        }
        if (pTemp->next != NULL && pTemp->next->data == data)
        {
            free(newVert);
            return pTemp->next; // Duplicate data
        }

        newVert->next = pTemp->next;
        pTemp->next = newVert;

        return newVert;
    }

    vert_t *vertAtIndex(vert_t *root, int index)
    {
        for (int i = 0; i < index; i++)
        {
            if (root == NULL)
            {
                return NULL;
            }
            root = root->next;
        }
        return root;
    }

    edge_t *insertEdge(edge_t **root, vert_t *tVert, int weight)
    {
        edge_t *newEdge = malloc(sizeof(edge_t));
        newEdge->weight = weight;
        newEdge->tVert = tVert;
        newEdge->next = NULL;

        if (*root == NULL || (*root)->tVert->data > tVert->data || ((*root)->tVert->data == tVert->data && (*root)->weight > weight))
        {
            newEdge->next = *root;
            *root = newEdge;
            return newEdge;
        }

        // Traverse through the linked list while sorting automatically
        edge_t *pTemp = *root;
        while (pTemp->next != NULL && (pTemp->next->tVert->data < tVert->data ||
                                    (pTemp->next->tVert->data == tVert->data && pTemp->next->weight < weight)))
        {
            pTemp = pTemp->next;
        }

        newEdge->next = pTemp->next;
        pTemp->next = newEdge;

        return newEdge;
    }

    int isFull(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                return 0;
            }
        }

        return 1;
    }

    void performDijkstra(vert_t *target, int n)
    {
        // Table list for shortest distances
        int *shortestDist = malloc(n * sizeof(int));
        int *visited = malloc(n * sizeof(int)); // boolean representation

        // Initialize values
        for (int i = 0; i < n; i++)
        {
            shortestDist[i] = 10000;
            visited[i] = 0;
        }

        // Dstance to self is 0
        shortestDist[target->data] = 0;

        vert_t *currentVertex = target;

        // Traverse the graph until every node is marked as visited
        while (currentVertex != NULL || !isFull(visited, n))
        {
            int minEdge = 10000;
            vert_t *minVert = NULL;
            edge_t *currentEdge = currentVertex->adj;

            while (currentEdge != NULL)
            {
                // Update the shortest distance
                int newDist = shortestDist[currentVertex->data] + currentEdge->weight;
                if (newDist < shortestDist[currentEdge->tVert->data])
                {
                    shortestDist[currentEdge->tVert->data] = newDist;
                }

                if (currentEdge->weight < minEdge && !visited[currentEdge->tVert->data])
                {
                    minEdge = currentEdge->weight;
                    minVert = currentEdge->tVert;
                }

                currentEdge = currentEdge->next;
            }

            visited[currentVertex->data] = 1; // Mark node as visited
            currentVertex = minVert;          // Continue traversing
        }

        // Output shortest distances
        for (int i = 0; i < n; i++)
        {
            printf("%d %d\n", i, shortestDist[i] >= 10000 ? -1 : shortestDist[i]);
        }

        free(shortestDist);
    }

    int main()
    {
        int n, s;
        scanf("%d %d", &n, &s);

        // Initialize vertex list
        vert_t *root = NULL;
        for (int i = 0; i < n; i++)
        {
            insertVert(&root, i);
        }

        // Init edges
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int weight;
                scanf("%d", &weight);
                if (weight == 0)
                {
                    continue;
                }

                insertEdge(&(vertAtIndex(root, i)->adj), vertAtIndex(root, j), weight);
            }
        }

        performDijkstra(vertAtIndex(root, s), n);

        return 0;
    }