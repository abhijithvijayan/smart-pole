#define FACTOR 0.026; // 26.4mA per count
#define CALFACTOR 513

class ACS712 : public AnalogReader {
  public:
    ACS712(int pin);
    virtual void calibrate(int calFactor = CALFACTOR);
    virtual float getVPP();
    virtual int getmVPerAmpValue();

  private:
    int _mVperAmp = 66; // use 100 for 20A Module and 66 for 30A Module and 185
                        // for 5A Module
    int _calFactor = 513;
};
