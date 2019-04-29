#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
    private:
        //there is two method to define the Lbs_per_stn
        enum{Lbs_per_stn = 14};
        // static consr int Lbs_per_stn = 14;
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();

        void show_lbs() const;
        void show_stn() const;
};

#endif