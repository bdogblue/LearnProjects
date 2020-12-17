// Box class definition

class box
{ public:
    box();                          // Constructor - empty
    ~box();                         // Destructor
    box(int,int);                   // Constructor - parameters
    bool   get(istream &in);        // Input dimensions
    void   put(ostream &out);       // Output dimensions
    float  area();                  // Calculate area
    float  perimeter();             // Calculate perimeter
  private:
    int height,width;               // Dimensions
};
