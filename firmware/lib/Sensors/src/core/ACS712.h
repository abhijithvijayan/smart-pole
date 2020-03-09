#define FACTOR 0.026; // 26.4mA per count
#define CALREADINGS 100
#define CALFACTOR 513

class ACS712 : public AnalogReader {
  public:
    ACS712(int pin);
    virtual void calibrate(int calFactor = CALFACTOR);
    virtual float getCurrent(int cals = CALREADINGS);

  private:
    int _calFactor = 513;
};
