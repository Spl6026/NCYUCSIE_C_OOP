class ptrMemberVarType {
public:
    void print() const;

    void insertAt(int index, int num);

    ptrMemberVarType(int size = 10);

    ~ptrMemberVarType();

    ptrMemberVarType(const ptrMemberVarType &otherObject);

private:
    int maxSize;
    int length;
    int *p;
};
