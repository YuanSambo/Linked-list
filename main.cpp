#include <iostream>
#include <vector>
#include <algorithm>


void  menu(){
    printf(" --------------- MAIN MENU --------------- \n");
    printf("| 1 - Add name to the boy's list.         |\n");
    printf("| 2 - Add name to the girl's list.        |\n");
    printf("| 3 - Display the boy's list.             |\n");
    printf("| 4 - Display the girl's list.            |\n");
    printf("| 5 - Merge and display the list.         |\n");
    printf("| 6 - Delete name in the boy's list.      |\n");
    printf("| 7 - Delete name in the girl's list.     |\n");
    printf("| 8 - End Program                         |\n");
    printf(" __________________________________________\n");
    printf("Enter your choice: ");
}


struct Node
{
    std::string  data;
    Node *next;
};

class List
{


public:
    Node *head,*tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(std::string name)
    {
        Node *newNode = new Node;
        newNode->data = name;
        newNode->next = NULL;


        // If the list is empty
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Links the new node next to the current tail.
            tail->next = newNode;
            //Assign the new node as the tail;
            tail = tail->next;
        }
    }

    void show_list(){

        // A pointer that stores the head node.
        Node* ptr = head;

        // Loop until the end of the list.
        while (ptr != NULL)
        {
            std::cout<<ptr->data<<"-->";

            // Moves the current pointer to the next node.
            ptr = ptr->next;
        }

        //If the current pointer is NULL.
        if(ptr == NULL){
            std::cout<<"NULL"<<std::endl;
        }     }

    bool deleteNode(std::string name)
    {

        // Pointer that stores the head node.
        Node* temp = head;
        Node* prev = NULL;

        // If the head node holds the name.
        if (temp != NULL && temp->data == name)
        {
            head = temp->next;      // Changed head
            delete temp;            // free old head
            return true;
        }


        // Looping the list until the name to be deleted is found.
        while (temp != NULL && temp->data != name)
        {
            prev = temp;
            temp = temp->next;
        }

        // If name was not present in linked list
        if (temp == NULL)
            return false;

        // Unlink the node from linked list
        prev->next = temp->next;

        // Free memory
        delete temp;
        return true;
    }
};

List merge_list(List list1,List list2){

    if(list1.head == NULL || list2.head == NULL){
        return list1;
    }

    std::vector<std::string> mergedList;

    //Stores the head of list1.
    Node* ptr1 = list1.head;
    //Stores the head of list2.
    Node* ptr2 = list2.head;


    // Loop until the end of the list.
    while (ptr1 != NULL)
    {
        mergedList.push_back(ptr1->data);
        // Moves the current pointer to the next node.
        ptr1 = ptr1->next;
    }

    // Loop until the end of the list.
    while (ptr2 != NULL)
    {
        mergedList.push_back(ptr2->data);
        // Moves the current pointer to the next node.
        ptr2 = ptr2->next;
    }

    // Sorts the data inside the vector alphabetically.
    std::sort(std::begin(mergedList), std::end(mergedList));

    // Stores the new sorted data;
    List newList;

    // Stores the sorted data in to the list.
    for(int y = 0; y < mergedList.size(); y++){
        newList.add_node(mergedList[y]);
    }

    // Returns the merged list.
    return newList;
}


int main()
{
    List boys;
    List girls;
    List merged;


    char choice;
    std::string entryName;

    while( choice!= '0' ) {

        menu();
        std::cin>>choice;

        switch(choice)
        {

            case '1':
                std::cout<<"Enter name : ";
                std::cin>>entryName;
                boys.add_node(entryName);
                std::cout<<"Added succesfully"<<std::endl;
                break;
            case '2':
                std::cout<<"Enter name : ";
                std::cin>>entryName;
                girls.add_node(entryName);
                std::cout<<"Added succesfully"<<std::endl;
                break;
            case '3':
                boys.show_list();
                break;
            case '4':
                girls.show_list();
                break;
            case '5':
                merged = merge_list(boys,girls);
                merged.show_list();
                break;
            case '6':
                std::cout<<"Enter the name you want to delete:";
                std::cin>>entryName;
                if(boys.deleteNode(entryName)){
                    std::cout<<"Remove succesfully\n";
                    boys.show_list();
                }else
                    std::cout<<"Name not found in the list \n";;
                break;
            case '7':
                std::cout<<"Enter the name you want to delete:";
                std::cin>>entryName;
                if(girls.deleteNode(entryName)){
                    std::cout<<"Remove succesfully\n";
                    girls.show_list();

                }else
                    std::cout<<"Name not found in the list \n";

                break;
            case '8':
                exit(0);
            default:
                printf("Please input valid choice\n ");
                break;
        }
    }


}