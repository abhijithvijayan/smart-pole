class AnalogReader {
  public:
    AnalogReader(int pin);
    virtual float read();

  private:
    int _pin;
};
