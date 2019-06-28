#ifndef TABTENN_H_
#define TABTENN_H_
#include <string>
using std::string;
class TableTennisPlayer
{
    private:
        string firstname;
        string lastname;
        bool hasTable;
    public:
        TableTennisPlayer(const string & fn = "none",
                        const string & ln = "none", bool ht = false);
        void Name() const;
        bool HasTable() const {return hasTable;};
        void ResetTable(bool v) {hasTable = v;}; 
};

//simple derived class
//if miss the "public", base class method can't be called in derive class
class RatePlayer : public TableTennisPlayer
{
    private:
        unsigned int rating;
    public:
        RatePlayer(unsigned int r = 0, const string & fn = "None",
                    const string & ln = "None", bool ht = false);
        RatePlayer(unsigned int r, const TableTennisPlayer & tb); 
        //r can't defind value, because td do not defind value
        unsigned int Rating() const {return rating;};
        void RestRating (unsigned int r) {rating = r;};
};


#endif