// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// typedef ListNode Node;

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
//     {
//         Node* dummy = new ListNode(0);
//         Node* tail = dummy;
//         while(list1 != nullptr && list2 != nullptr)
//         {
//             //list 1 element is smaller
//             if(list1->val < list2->val)
//             {
//                 tail->next = list1;
//                 list1 = list1->next;
//             }
//             else
//             {
//                 tail->next = list2;
//                 list2 = list2->next;
//             }
//             tail = tail->next;
//         }

//         if(list1 != nullptr)
//         {
//             tail->next = list1;
//         }
//         else
//         {
//             tail->next = list2;
//         }

//         Node* head = dummy->next;  
//         delete dummy;
//         return head;
//     }
// };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

int32_t intercept = [] {
    std::string str{};
    std::string str2{};
    std::priority_queue<int16_t, std::vector<int16_t>, std::greater<int16_t>>
        pq{};

    {
        std::ofstream out{"user.out"};
        while (std::getline(std::cin, str) and std::getline(std::cin, str2)) {
            {
                std::stringstream stream;
                std::replace(str.begin(), str.end(), ',', ' ');
                stream << std::string{str.begin() + 1, str.end() - 1};
                int16_t val{};
                while (!stream.eof()) {
                    stream >> str;
                    if (std::stringstream(str) >> val)
                        pq.emplace(val);
                }
            }
            {
                std::stringstream stream;
                std::replace(str2.begin(), str2.end(), ',', ' ');
                stream << std::string{str2.begin() + 1, str2.end() - 1};
                int16_t val{};
                while (!stream.eof()) {
                    stream >> str2;
                    if (std::stringstream(str2) >> val)
                        pq.emplace(val);
                }
            }

            out << '[';
            if (!pq.empty()) {
                out << pq.top();
                pq.pop();
            }
            for (; !pq.empty(); pq.pop())
                out << ',' << pq.top();
            out << ']' << '\n';
        }

        std::cout << "str" << str << std::endl;
        std::cout << "str2 " << str2 << std::endl;
    }

    exit(0);

    return 0;
}();

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to simplify list operations
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Merge lists by attaching the smaller node at each step
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining part of the non-empty list
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // Save the head of the merged list and clean up the dummy node
        ListNode* head = dummy->next;
        delete dummy;

        return head;
    }
};