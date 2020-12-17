#ifndef LIST_H
#define LIST_H


class list
{
    public:
        list();
        ~list();
        bool append(float);
        float avg();
        bool resize(int);
        void operator = (const list);

    private:
        int size, len;
        float *data;
};

#endif // LIST_H
