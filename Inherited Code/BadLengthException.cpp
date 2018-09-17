/* Define the exception here */

class BadLengthException : public exception
{
    private:
    string error_message;
    public:
    BadLengthException(int n) : error_message(to_string(n)) {}
    
    const char * what () const throw ()
    {
        return error_message.c_str();
    }
};
