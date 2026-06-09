class DynamicArray {
public:
    int capacityDynamic = 0;
    int index = 0;
    std::unique_ptr<int[]> arr = nullptr;

    DynamicArray(int capacity) {
        capacityDynamic = capacity;
        std::unique_ptr<int[]> newarr = std:: make_unique<int[]>(capacityDynamic);
        arr = std::move(newarr);
    }

    int get(int i) {

        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(index == capacityDynamic)
        {
            resize();
        }
        arr[index++] = n;
    }

    int popback() {

        return arr[--index];
    }

    void resize() {
        capacityDynamic *= 2U;
        std::unique_ptr<int[]> newarr = std:: make_unique<int[]>(capacityDynamic);
        for (int i = 0; i < index; i++)
        {
            newarr[i] = arr[i];
        }
        arr = std::move(newarr);
    }

    int getSize() {
        return index;
    }

    int getCapacity() {
        return capacityDynamic;
    }
};
