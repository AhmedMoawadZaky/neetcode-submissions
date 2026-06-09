class LinkedList {
public:
    class listNode
    {
        public:
        int value;
        listNode * nextNode = nullptr;
        listNode();
        listNode(int val)
        {
            value = val;
        }
    };
    int sizeOfList = 0;
    int iterOnList = 0;
    listNode * head;
    listNode * tail;
    listNode * cur;
    listNode * temp;
    listNode * previous;
    
    LinkedList() {
        head = new listNode(-1);
        tail = head;
    }

    int get(int index) {
        if(index >= sizeOfList)
        {
            return -1;
        }
        cur = head;
        iterOnList = 0;
        while(cur != nullptr && iterOnList < index)
        {
            iterOnList += 1;
            cur = cur->nextNode;
        }
        return cur->value;
    }

    void insertHead(int val) {
        if(head->value == -1)
        {
            head->value = val;
        }
        else
        {
            cur = new listNode(val);
            cur->nextNode = head;
            head = cur;
        }
        sizeOfList += 1;
    }
    
    void insertTail(int val) {
        if(tail->value == -1)
        {
            tail->value = val;
        }
        else
        {
            cur = new listNode(val);
            tail->nextNode = cur;
            tail = cur;
        }
        sizeOfList += 1;
    }

    bool remove(int index) {
        if(index >= sizeOfList)
        {
            return false;
        }
        cur = head;
        iterOnList = 0;
        while(cur != nullptr && iterOnList < index)
        {
            iterOnList += 1;
            previous = cur;
            cur = cur->nextNode;
        }
        if(head == cur)
        {
            temp = head;
            head = head->nextNode;
            if(cur == tail)
            {
                tail = nullptr;
            }
        }
        else
        {
            temp = cur;
            previous->nextNode = cur->nextNode;
            if(cur == tail)
            {
                tail = previous;
            }
        }
        delete temp;
        sizeOfList -= 1;
        return true;
    }

    vector<int> getValues() {
        vector<int> ansValues;
        cur = head;
        while(cur != nullptr)
        {
            if(cur->value != -1)
            {
                ansValues.push_back(cur->value);
            }
            cur = cur->nextNode;
        }
        return ansValues;
    }
};
