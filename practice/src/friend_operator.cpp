#include <iostream>
#include <vector>
class User
{
    static int user_count;
    std::string status = "Gold";

    public:
        static int get_user_count(){
            return user_count;
        }
        std::string first_name, last_name;
        std::string get_status(){
            return status;
        }
        void set_status(std::string status){
            if(status=="Gold" || status == "Silver" || status == "Bronze"){
                (*this).status = status;
            }else{
                this->status = "No status";
            }
        }
        User()
        {
            user_count ++;
        }
        User(std::string first_name, std::string last_name, std::string status){
            this->first_name = first_name;
            this->last_name = last_name;
            this->status = status;
            user_count++;
        }
        ~User()
        {
            user_count--;
        }
        // friend void output_status(User user);
        friend std::ostream& operator<< (std::ostream& output, const User user);
};

int User::user_count = 0;

// void output_status(User user){
//     std::cout << user.status << "\n";
// }

int add_user_if_not_exists(std::vector<User> &users, User user){

}

std::ostream& operator<< (std::ostream& output, const User user){
    output << "First name: " << user.first_name << "\nLast name: " << user.last_name << "\nStatus: " << user.status;
    return output;
}

std::istream& operator >> (std::istream& input, User& user){
    input >> user.first_name >> user.last_name;
    return input;
}

int main(){
    User user;
    std::cin >> user;
    // output_status(user);
    std::cout << user << "\n";

}