#include <stdio.h>

void recordStatus(int hos[][5])
{
    char wardNames[3][10] = {
        "General",
        "ICU",
        "Private"
    };
    printf("\n---Update Records---");
    int inp, inpArray[3][5];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("\nEnter status of Bed number %d of %s ward: (0/1)",j+1, wardNames[i]);
            scanf("%d",&inp);
            if (inp != 0 && inp != 1)
            {
                printf("\nInvalid Input!");
                return;
            }
            inpArray[i][j] = inp;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            hos[i][j] = inpArray[i][j];
        }
    }
}
void displayStatus(int hos[][5])
{
    if (hos[0][0] != 0 && hos[0][0] != 1)
    {
        printf("\nNo Current Records, Update them First!");
        recordStatus(hos);
        if (hos[0][0] != 0 && hos[0][0] != 1)
        {
            printf("\nError! Failed to enter records");
            return;
        }
    }
    char wardNames[3][10] = {
        "General",
        "ICU",
        "Private"
    };
    int *p = &hos[0][0];
    printf("\n---Current Status---");
    for (int i = 0; i < 3; i++)
    {
        int ec=0,oc=0;
        printf("\n--%s Ward--",wardNames[i]);
        for (int j = 0; j < 5; j++)
        {
            if ( *( p + (i * 5 + j) ) == 0)
            {
                ec++;
                printf("Bed %d: Empty",j+1);
            }
            else if ( *( p + (i * 5 + j) ) == 1)
            {
                oc++;
                printf("Bed %d: Occupied",j+1);
            }
        }
        printf("\nTotal Number Of Empty Beds: %d", ec);
        printf("\nTotal Number Of Occupied Beds: %d", oc);
    }
    printf("\n-End-");
}
int main() {
    int hospital[3][5] = {
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
    };
    int inp=-1;

    while (inp != 0)
    {
        printf("\n----Hospital Record Management----");
        printf("\n1. Update Current Records");
        printf("\n2. Current Status of All Wards");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&inp);
        switch (inp)
        {
            case 1:
            recordStatus(hospital);
            break;
            case 2:
            displayStatus(hospital);
            break;
            default:
            printf("\nInvalid Choice!");
            break;
        }
    }
    printf("\nExiting...");
    return 0;
}
