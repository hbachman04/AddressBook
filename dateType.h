
#ifndef H_dateType
#define H_dateType

class dateType
{
public:
    void setDate(int month, int day, int year);
    void getDate(int& month, int& day, int& year) const;
    void printDate() const;

    dateType(int month = 1, int day = 1, int year = 2000);

private:
    int dMonth;
    int dDay;
    int dYear;
};

#endif
