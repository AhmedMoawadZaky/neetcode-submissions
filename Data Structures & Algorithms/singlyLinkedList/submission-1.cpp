class LinkedList {
public:
      class listNode {
    public:
        int value;
        listNode* nextNode;

        listNode(int val) : value(val), nextNode(nullptr) {}
    };

    int sizeOfList = 0;
    listNode* head = nullptr;
    listNode* tail = nullptr;

public:
    LinkedList() = default;

    ~LinkedList() {
        listNode* cur = head;
        while (cur != nullptr) {
            listNode* temp = cur;
            cur = cur->nextNode;
            delete temp;
        }
    }

    int get(int index) {
        if (index < 0 || index >= sizeOfList) return -1;

        listNode* cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->nextNode;
        }
        return cur->value;
    }

    void insertHead(int val) {
        listNode* newNode = new listNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->nextNode = head;
            head = newNode;
        }
        sizeOfList++;
    }

    void insertTail(int val) {
        listNode* newNode = new listNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->nextNode = newNode;
            tail = newNode;
        }
        sizeOfList++;
    }

    bool remove(int index) {
        if (index < 0 || index >= sizeOfList) return false;

        listNode* cur = head;
        listNode* previous = nullptr;

        for (int i = 0; i < index; ++i) {
            previous = cur;
            cur = cur->nextNode;
        }

        if (cur == head) {
            head = head->nextNode;
            if (cur == tail) tail = nullptr;
        } else {
            previous->nextNode = cur->nextNode;
            if (cur == tail) tail = previous;
        }

        delete cur;
        sizeOfList--;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        listNode* cur = head;
        while (cur != nullptr) {
            values.push_back(cur->value);
            cur = cur->nextNode;
        }
        return values;
    }
};
