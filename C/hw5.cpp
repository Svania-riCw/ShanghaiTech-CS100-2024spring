#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <memory>


class Comment {
private:
    std::string content_;
    std::string commenter_;
    time_t timestamp_;

public:
    Comment(const std::string& content, const std::string& commenter)
        : content_(content), commenter_(commenter), timestamp_(std::time(nullptr)) {}

    std::string getcontent() const { return content_; }
    std::string getcommenter() const { return commenter_; }
    time_t gettmestamp() const { return timestamp_; }

    void display() const {
        std::string time_str = std::asctime(std::localtime(&timestamp_));
        time_str.erase(time_str.find_last_not_of('\n') + 1);
        std::cout << commenter_ << ": " << content_ << " (" << time_str << ")" << " ";
    }
};



class Like {
private:
    std::string liker_;
    time_t timestamp_;

public:
    explicit Like(const std::string& liker)
        : liker_(liker), timestamp_(std::time(nullptr)) {}

    std::string getliker() const { return liker_; }
    time_t gettimestamp() const { return timestamp_; }

    void display() const {
        std::string time_str = std::asctime(std::localtime(&timestamp_));
        time_str.erase(time_str.find_last_not_of('\n') + 1);
        std::cout << liker_ << " liked this post" << " (" << time_str << ")" << " ";
    }
};

class Post {
private:
    std::string content_;
    std::string author_;
    time_t timestamp_;
    bool ispublic_;
    std::vector<Comment> comments_;
    std::vector<Like> likes_;

public:
    Post(const std::string& content, const std::string& author, bool ispublic = true)
        :content_(content), author_(author), timestamp_(std::time(nullptr)), ispublic_(ispublic) {}

    void addcomment(const std::string& content, const std::string& commenter){
        comments_.emplace_back(content, commenter);
    }

    void addlike(const std::string& liker) {
        likes_.emplace_back(liker);
    }

    void setvisibility(bool ispublic) {
        ispublic_ = ispublic;
    }

    std::string getcontent() const { return content_; }

    std::string getauthor() const { return author_; }

    bool ispublic() const { return ispublic_; }

    time_t gettimestamp() const { return timestamp_; }

    void display() const {
        if (!ispublic_) {
            std::cout << "this is private" << std::endl;
            return;
        }

        std::string time_str = std::asctime(std::localtime(&timestamp_));
        time_str.erase(time_str.find_last_not_of('\n') + 1);
        std::cout << author_ << " 's post (" << time_str << "):\n";
        std::cout << content_ << "\n\n";
        std::cout << "likes_(" << likes_.size() << "):\n";
        for (const auto& Like : likes_) {
            Like.display();
        }

        std::cout << "\ncomments (" << comments_.size() << "):\n";
        for (const auto& Comment : comments_) {
            Comment.display();
        }
        std::cout << std::endl;
    }
};


class User {
private:
    std::string name_;
    std::vector<std::shared_ptr<Post>> posts_;

public:
    explicit User(const std::string& name) : name_(name) {}

    std::shared_ptr<Post> createpost(const std::string& content, bool ispublic = true) {
        auto newpost = std::make_shared<Post>(content, name_, ispublic);
        posts_.emplace_back(newpost);
        return newpost;
    }

    std::string getname() const { return name_;}

    void displaypost() const {
        std::cout << name_ << "'s posts (" << posts_.size() << "):\n";
        for (const auto& Post : posts_) {
            Post->display();
            std::cout << "----------------\n\n";
        }
    }
};


int main() {
    User andy("Andy");
    User bob("Bob");
    User candy("charlie");

    auto post1 = andy.createpost("Hello, world!");
    auto post2 = andy.createpost("I HAD A GOOD DAY!", false); //私有帖子
    auto post3 = bob.createpost("123 + 321 = 444");

    post1->addlike("Bob");
    post1->addlike("candy");
    post1->addcomment("Nice!", "Bob");
    post3->addcomment("good job!", "candy");

    post2->setvisibility(false);

    andy.displaypost();
    bob.displaypost();

    std::cout << "post1 Author: " << post1->getauthor() << "\n";
    std::cout << "post1 Content: " << post1->getcontent() << "\n";
    std::cout << "Is post 2 Public? " << (post2->ispublic() ? "Yes!" : "No.") << "\n";

    return 0;
}