// Define specializations for the Traits class template here.

template <> struct Traits<Color> {
    static string name(int n) {
        Color m = (Color) n;
        switch(m)
        {
            case Color::red    : return "red";     break;
            case Color::green  : return "green";   break;
            case Color::orange : return "orange";  break;
            default     : return "unknown"; break;
        }
    }    
};
template <> struct Traits<Fruit> {
    static string name(int n) {
        Fruit m = (Fruit) n;
        switch(m) {
            case Fruit::apple  : return "apple";   break;
            case Fruit::orange : return "orange";  break;
            case Fruit::pear   : return "pear";    break;
            default     : return "unknown"; break;
        }
    }    
};
