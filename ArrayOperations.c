#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, n, i, choice;
    int value, pos, found;

    printf("Enter array size: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid array size!\n");
        return 0;
    }

    arr = malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Display Array\n");
        printf("2. Insert Value\n");
        printf("3. Delete Value\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Array elements: ");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }

                printf("\n");
                break;

            case 2:
                printf("Enter position to insert: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n + 1)
                {
                    printf("Invalid position!\n");
                    break;
                }

                printf("Enter value: ");
                scanf("%d", &value);

                int *temp;
                temp = realloc(arr, (n + 1) * sizeof(int));

                if(temp == NULL)
                {
                    printf("Memory allocation failed!\n");
                    break;
                }

                arr = temp;

                for(i = n; i >= pos; i--)
                {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                printf("Value inserted successfully!\n");
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(arr[i] == value)
                    {
                        found = 1;
                        break;
                    }
                }

                if(found)
                {
                    for(; i < n - 1; i++)
                    {
                        arr[i] = arr[i + 1];
                    }

                    n--;

                    printf("Value deleted successfully!\n");
                }
                else
                {
                    printf("Value not found!\n");
                }

                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    free(arr);

    return 0;
}
