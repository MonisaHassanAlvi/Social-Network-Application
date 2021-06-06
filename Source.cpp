#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<conio.h>
class object
{
private:
	char* id;

public:
	object()                                         //default constructor
	{
		id = 0;
	}
	object(const object & obj)                         //copy constructor
	{
		if (obj.id == 0)
		{
			int len = strlen(obj.id);
			id = new char[len + 1];
			strcpy_s(id, len + 1, obj.id);
		}
		else
		{
			id = 0;
		}
	}
	const object& operator=(const object& obj)             //assignment operator
	{
		if (&obj != this)
		{
			if (obj.id != 0)
			{
				if (strlen(id) == strlen(obj.id))
				{
					strcpy_s(id, strlen(id) + 1, obj.id);
				}
				else if (id == 0)
				{
					int len = strlen(obj.id);
					id = new char[len + 1];
					strcpy_s(id, len + 1, obj.id);
				}
				else
				{
					delete[] id;
					int len = strlen(obj.id);
					id = new char[len + 1];
					strcpy_s(id, len + 1, obj.id);
				}
			}
			else
				id = obj.id;
		}
		return *this;
	}
	void Setid(char ch[])
	{
		int len = strlen(ch);
		id = new char[len + 1];
		strcpy_s(id, len + 1, ch);
	}
	char* Getid()
	{
		return id;
	}
	~object()
	{
		if (id != 0)
		{
			delete[] id;
		}
	}
	virtual char* getName() = 0;
	virtual void printListView() = 0;
};
class Date
{
private:
	int year;
	int month;
	int day;


public:
	Date()         //default constructor
	{
		year = 0;
		month = 0;
		day = 0;
	}
	Date(int y, int m, int d)  //overloaded constructor
	{
		year = y;
		month = m;
		day = d;
	}
	Date(const Date & obj)     //copy constructor
	{
		year = obj.year;
		month = obj.month;
		day = obj.day;
	}
	bool operator<(const Date &obj)      //less than operator
	{
		if (year == obj.year && month == obj.month && day == obj.day - 1)
			return true;
		else
			return false;
	}
	bool operator==(const Date & obj)    //double equal to operator
	{
		if (year == obj.year && month == obj.month && day == obj.day)
			return true;
		else
			return false;
	}
	void setDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	int getday()
	{
		return day;
	}
	void printDate()
	{
		cout << year << "/" << month << "/" << day;
	}
};
class Comment
{
private:
	object** id;
	object** commentUser;
	char* comment;
public:
	Comment()         //default constructor
	{
		id = 0;
		commentUser = 0;
		comment = 0;
	}
	void setId(char* ch)
	{
		if (id == 0)
			id = new object*;
	}
	void setCommentUser(object* obj)
	{
		if (commentUser == 0)
		{
			commentUser = new object*;
		}
		(*(commentUser)) = obj;
	}
	void setcomment(char* ch)
	{
		int len = strlen(ch);
		comment = new char[len + 1];
		strcpy_s(comment, len + 1, ch);
	}
	~Comment()
	{
		if (commentUser != 0)
		{
			delete[] commentUser;
		}
		if (comment != 0)
		{
			delete[] comment;
		}
	}
	void printComment()
	{
		if (commentUser != 0)
		{
			cout << "\t\t\t\t" << (*(commentUser))->getName() << " wrote:\" " << comment << "\"" << endl;
		}
	}
};
class Post : public object
{
private:
	object** likes;
	int totalNoofLikes;
	Date postSharedDate;
	Comment** comments;
	int countofComments;
	char* description;
	int countofLikes;

public:
	Post()                      //defualt constructor
	{
		likes = 0;
		totalNoofLikes = 0;
		comments = 0;
		countofComments = 0;
		description = 0;
		countofLikes = 0;
	}
	Date getDate()
	{
		return postSharedDate;
	}
	void setDate(Date date)
	{
		postSharedDate = date;
	}
	Post(const Post & obj)         //copy constructor
	{
		likes = new object*[10];
		int i = 0;
		while (i<10)
		{
			if (obj.likes != 0)
				likes[i] = obj.likes[i];
			else
				likes[i] = 0;
			i++;
		}
		totalNoofLikes = obj.totalNoofLikes;
		postSharedDate = obj.postSharedDate;
		int len = strlen(obj.description);
		description = new char[len + 1];
		strcpy_s(description, len + 1, obj.description);
	}
	const Post &operator = (Post & obj)         //assignment operator
	{
		if (&obj != this)
		{
			likes = new object*[10];
			int i = 0;
			while (i<10)
			{
				if (obj.likes != 0)
					likes[i] = obj.likes[i];
				else
					likes[i] = 0;
				i++;
			}
			totalNoofLikes = obj.totalNoofLikes;
			postSharedDate = obj.postSharedDate;
			int len = strlen(obj.description);
			description = new char[len + 1];
			strcpy_s(description, len + 1, obj.description);
			this->Setid(obj.Getid());
		}
		return *this;
	}
	void setDescription(char* des)
	{
		int len = strlen(des);
		description = new char[len + 1];
		strcpy_s(description, len + 1, des);
	}
	void printListView()
	{
		cout << "\"" << description;
		cout << " \"...( ";
		postSharedDate.printDate();
		cout << ")" << endl;
	}
	char* getName()
	{
		return description;
	}
	void printComments()
	{
		int i = 0;
		if (comments != 0)
		{
			while (i<10)
			{
				if (comments[i] != 0)
				{
					comments[i]->printComment();
				}
				i++;
			}
		}
	}
	void setPost(int year, int month, int day, char* postId, char* des)
	{
		postSharedDate.setDate(year, month, day);
		this->Setid(postId);
		int len = strlen(des);
		description = new char[len + 1];
		strcpy_s(description, len + 1, des);
	}
	void print()
	{
		this->printListView();
		this->printComments();
	}
	void setPostComments(Comment & comment)
	{
		if (countofComments<10)
		{
			if (comments == 0)
			{
				comments = new Comment*[10];
				int i = 0;
				while (i<10)
				{
					comments[i] = 0;
					i++;
				}
			}
			comments[countofComments] = &comment;
			countofComments++;
		}
		else
		{
			cout << endl << "MAXIMUM COMMENT LIMIT IS REACHED " << endl;
		}
	}
	void addComments(Comment& comment)
	{
		if (comments == 0)
		{
			comments = new Comment*[10];
			int i = 0;
			while (i<10)
			{
				comments[i] = 0;
				i++;
			}
		}
		comments[countofComments] = &comment;
		countofComments++;
	}
	void setTotalLikes(int n)
	{
		totalNoofLikes = n;
	}
	void printLikedbyList()
	{
		if (likes != 0)
		{
			int i = 0;
			while (i< countofLikes)
			{
				likes[i]->printListView();
				i++;
			}
		}
		else
		{
			cout << endl << "NO ONE LIKED THE POST" << endl;
		}
	}
	void SetLikes(object* lk)
	{
		if (likes == 0)
		{
			likes = new object*[10];
			for (int j = 0; j<10; j++)
			{
				likes[j] = 0;
			}
		}
		likes[countofLikes] = lk;
		countofLikes++;
	}
	void AddLikes(object* lk)
	{
		if (countofLikes<10)
		{
			likes[countofLikes] = lk;
			countofLikes++;
		}
		else
		{
			cout << endl << "MAXIMUM LIKED LIMIT IS REACHED" << endl;
		}
	}
	~Post()            //destructor
	{
		if (likes != 0)
		{
			int i = 0;
			while (i<countofLikes)
			{
				delete likes[i];
				i++;
			}
		}
		if (comments != 0)
		{
			int i = 0;
			while (i<countofComments)
			{
				delete comments[i];
				i++;
			}
		}
		if (description != 0)
		{
			delete[] description;
		}
	}
};
class Page : public object
{
private:
	Post** timeline;
	int posts;
	int totalLikes;
	char* pageName;
public:
	Page()                     //default constructor
	{
		timeline = 0;
		posts = 0;
		totalLikes = 0;
		pageName = 0;
	}
	void setPage(char* name, char* id)
	{
		int len = strlen(name);
		pageName = new char[len + 1];
		strcpy_s(pageName, len + 1, name);
		object::Setid(id);
	}
	char* getName()
	{
		return pageName;
	}
	void setTimeLine(Post& post)
	{
		if (timeline == 0)
		{
			timeline = new Post*[10];
			int i = 0;
			while (i < 10)
			{
				timeline[i] = 0;
				i++;
			}
		}
		timeline[posts] = &post;
		posts++;
	}
	void printTimeLine()
	{
		int i = 0;
		while (i<posts)
		{
			if (timeline[i] != 0)
			{
				cout << "---";
				timeline[i]->print();
			}
			i++;
			cout << endl;
		}
	}
	char* getPageName()
	{
		return pageName;
	}
	void printListView()
	{
		cout << Getid() << " - " << pageName << endl;
	}
	~Page()                 //destructor
	{
		if (timeline != 0)
		{
			delete[] timeline;
		}
		if (pageName != 0)
		{
			delete[] pageName;
		}
	}
	void printtimeline();
};
class User : public object
{
private:
	Post** timeLine;
	Page** likedList;
	User** friendList;
	char* fname;
	char* lname;
	int posts;
public:
	User()         //default constructor
	{
		timeLine = 0;
		likedList = 0;
		friendList = 0;
		fname = 0;
		lname = 0;
		posts = 0;
	}
	char* getName()
	{
		char* ch = new char[];
		int i = 0;
		int len = strlen(fname);
		while (i<len)
		{
			ch[i] = fname[i];
			i++;
		}
		ch[i] = ' ';
		i++;
		int j = 0;
		int len1 = strlen(lname) + 1;
		while (j<len1)
		{
			ch[i] = lname[j];
			i++;
			j++;
		}
		return ch;
	}
	void setUser(char* fn, char* ln, char* id)
	{
		int len = strlen(fn);
		fname = new char[len + 1];
		strcpy_s(fname, len + 1, fn);
		len = strlen(ln);
		lname = new char[len + 1];
		strcpy_s(lname, len + 1, ln);
		object::Setid(id);
	}
	void printtimeline();
	void ViewHomePage()
	{
		cout << fname << " " << lname << "-Home Page\n\n";

		if (friendList != 0)
		{
			int i = 0;
			while (i<10)
			{
				if (friendList[i] != 0)
				{
					friendList[i]->printtimeline();
				}
				i++;
			}
		}
		if (likedList != 0)
		{
			int i = 0;
			while (i<10)
			{
				if (likedList[i] != 0)
				{
					likedList[i]->printtimeline();
				}
				i++;
			}
		}
		cout << endl << endl << "-----------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	void printTimeLine()
	{
		if (timeLine != 0)
		{
			int i = 0;
			while (i<posts)
			{
				if (timeLine[i] != 0)
				{
					cout << "---";
					timeLine[i]->print();
				}
				i++;
				cout << endl;
			}
		}
	}
	void setTimeLine(Post& post)
	{
		if (timeLine == 0)
		{
			timeLine = new Post*[10];
			int j = 0;
			while (j<10)
			{
				timeLine[j] = 0;
				j++;
			}
		}

		timeLine[posts] = &post;
		posts++;
	}
	void setFriends(User& u, int i)
	{
		if (i == 0)
		{
			friendList = new User*[10];
			int j = 0;
			while (j<10)
			{
				friendList[j] = 0;
				j++;
			}
		}
		friendList[i] = &u;
	}
	void setPages(Page& p, int i)
	{
		if (i == 0)
		{
			likedList = new Page*[10];
			int j = 0;
			while (j<10)
			{
				likedList[j] = 0;
				j++;
			}
		}
		likedList[i] = &p;
	}
	void SharePost(Post & post);
	char* getlname()
	{
		return lname;
	}
	char* getfname()
	{
		return fname;
	}
	virtual void printListView()
	{
		cout << Getid() << " - " << fname << " " << lname << endl;
	}
	void viewFriendList()
	{
		cout << "Comand:\tView Friend List" << endl;
		cout << endl << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << this->fname << " " << this->lname << "-Friend List \n\n\n";
		if (friendList == 0)
		{
			cout << endl << "CURRENTLY NO FRIENDS ARE AVALIABLE" << endl;
		}
		else
		{
			int i = 0;
			while (i<10)
			{
				if (friendList[i] != 0)
				{
					friendList[i]->printListView();

				}
				i++;
			}
		}
		cout << endl << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	void viewLikedPages()
	{
		cout << "Comand:\tView Liked Pages" << endl;
		cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << this->fname << " " << this->lname << "-Liked Pages " << endl << endl << endl;
		if (likedList == 0)
		{
			cout << endl << "NO LIKED PAGES AVALIABLE" << endl;
		}
		else
		{
			int i = 0;
			while (i<10)
			{
				if (likedList[i] != 0)
				{
					likedList[i]->printListView();
				}
				i++;
			}
		}
		cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
	}
	~User()
	{
		if (timeLine)
		{
			delete[] timeLine;
		}
		if (likedList)
		{
			delete[] likedList;
		}
		if (friendList)
		{
			delete[] friendList;
		}
		if (fname != 0)
		{
			delete[] fname;
		}
		if (lname != 0)
		{
			delete[] lname;
		}
	}
};
class Helper
{
public:
	static bool searchString(char* str, char* key)
	{
		bool check = false;
		int i = 0;
		int j = 0;
		while (str[i] != '\0')
		{
			if (check == false && key[0] == str[i])
			{
				j = 0; check = true;
				while (check && key[j] != '\0')
				{
					if (key[j] == str[i])
					{
						check = true;
						i++;
						j++;
					}
					else
					{
						check = false;
						j++;
					}
				}
			}
			else
			{
				i++;
			}
		}
		return check;
	}
};
class SocialNetworkApplication
{
private:
	static Date* currentDate;
	Comment** comments;
	Post** post;
	Page** page;
	User** users;
	User*  currentUser;
public:
	SocialNetworkApplication()
	{
		comments = 0;
		post = 0;
		page = 0;
		users = 0;
		currentUser = 0;
	}
	static Date getDate()
	{
		return *currentDate;
	}
	void filing()     //This function reads the data from files
	{
		char buffer[100];
		char arr[20][70];
		ifstream fin;
		int user = 0;
		fin.open("174098-Project-SocialNetworkUsers.txt");
		fin >> user;                                   //reading the first line from file i.e the number of total users
		users = new User*[user];
		fin.getline(buffer, 100);
		int i = 0;
		char ch;
		while (!fin.eof())
		{
			users[i] = new User;
			char id[30];
			char fname[50];
			char lname[50];
			fin >> id;
			fin >> fname;
			fin >> lname;
			users[i]->setUser(fname, lname, id);
			fin.get(ch);
			fin.getline(arr[i], 70);
			i++;
		}
		fin.close();

		fin.open("174098-Project-SocialNetworkPages.txt");
		int pages = 0;
		fin >> pages;                         //reading the first line from file i.e the number of total pages
		page = new Page*[pages];
		fin.getline(buffer, 100);
		i = 0;
		while (!fin.eof())
		{
			page[i] = new Page;
			char pageId[30];
			char pageName[100];
			fin >> pageId;
			fin.getline(pageName, 100);
			page[i]->setPage(pageName, pageId);
			i++;
		}
		fin.close();
		i = 0;
		int j = 0;
		while (j<20)
		{
			i = 0;
			int k = 0;
			for (; arr[j][k] != '-';)                   // this checks the terminating condition of "-" and tab of users 
			{
				char c[4];
				int a = 0;
				for (; arr[j][k] != '\t';)
				{
					c[a] = arr[j][k];
					a++;
					k++;
				}
				c[a] = '\0';
				k++;
				int b = 0;
				while (b<20)
				{
					if (!strcmp(c, users[b]->Getid()))
					{
						users[j]->setFriends(*users[b], i);
						i++;
						break;
					}
					b++;
				}
			}
			i = 0;
			k = k + 3;
			for (; arr[j][k] != '-';)             //this checks the terminating condition of "-" and tab of pages 
			{
				char c[4];
				int a = 0;
				while (arr[j][k] != '\t')
				{
					c[a] = arr[j][k];
					a++;
					k++;
				}
				c[a] = '\0';
				k++;
				int b = 0;
				while (b<12)
				{
					if (!strcmp(c, page[b]->Getid()))
					{
						users[j]->setPages(*page[b], i);
						i++;
						break;
					}
					b++;
				}
			}
			j++;
		}
		fin.open("174098-Project-SocialNetworkPosts.txt");
		int posts;
		fin >> posts;                       //reading the first line from file i.e total no posts
		j = 0;
		while (j <= 7)
		{
			fin.getline(buffer, 100);
			j++;
		}
		post = new Post*[posts];
		int day;
		int month;
		int year;
		char postId[30];
		char postDescription[100];
		char sharedId[30];
		char likedId[30];
		int a = 0;
		int b = 0;
		i = 0;
		while (!fin.eof())
		{
			a = 0;
			post[i] = new Post;
			fin.getline(postId, 30);
			//fin >> postId;
			fin >> day;
			fin >> month;
			fin >> year;
			fin.getline(buffer, 100);
			fin.getline(postDescription, 100);
			post[i]->setPost(day, month, year, postId, postDescription);

			fin.getline(sharedId,30);
			int j = 0;
			while (j<20)
			{
				if (!strcmp(sharedId, users[j]->Getid()))
				{
					users[j]->setTimeLine(*post[i]);
					a++;

				}
				j++;
			}
			a = 0;
			j = 0;
			while (j<12)
			{
				if (!strcmp(sharedId, page[j]->Getid()))
				{
					page[j]->setTimeLine(*post[i]);
					a++;

				}
				j++;
			}
			char c[3] = "-1";
			fin >> likedId;
			a = 0;
			while (strcmp(c, likedId))
			{
				a = 0;
				int j = 0;
				while (j<20)
				{
					if (!strcmp(likedId, users[j]->Getid()))
					{
						post[i]->SetLikes(users[j]);
						break;
					}
					j++;
				}
				a = 0;
				j = 0;
				while (j<12)
				{
					if (!strcmp(likedId, page[j]->Getid()))
					{
						post[i]->SetLikes(page[j]);
						break;
					}
					j++;
				}
				fin >> likedId;
			}
			post[i]->setTotalLikes(b);
			fin.getline(buffer, 100);
			fin.getline(buffer, 100);
			i++;
		}
		fin.close();

		char BUFFER[200];
		int cmments;
		fin.open("174098-Project-SocialNetworkComments.txt");
		fin >> cmments;                   //reading the first line from file i.e total no of comments
		comments = new Comment*[cmments];
		fin.getline(BUFFER, 200);
		fin.getline(BUFFER, 200);
		fin.getline(BUFFER, 200);
		fin.getline(BUFFER, 200);
		i = 0;
		int k = 0;
		char commentId[30];
		char commentUser[30];
		char comment[100];
		while (!fin.eof())
		{
			comments[i] = new Comment;
			fin >> commentId;
			fin >> postId;
			fin >> commentUser;
			fin.getline(comment, 100);
			comments[i]->setId(commentId);
			comments[i]->setcomment(comment);
			int j = 0;
			while (j<20)
			{
				if (!strcmp(commentUser, users[j]->Getid()))
				{
					comments[i]->setCommentUser(users[j]);
				}
				j++;
			}
			j = 0;
			while (j<12)
			{
				if (!strcmp(commentUser, page[j]->Getid()))
				{
					comments[i]->setCommentUser(page[j]);
				}
				j++;
			}
			j = 0;
			while (j<11)
			{
				if (!strcmp(postId, post[j]->Getid()))
				{
					post[j]->setPostComments(*comments[i]);
				}
				j++;
			}
			i++;
		}
		fin.close();
	}
	static int GetCurrentDay()
	{
		return currentDate->getday();
	}
	void setCurrentUser(char* ch)
	{
		cout << "Command:\tSet current user \"" << ch << "\"" << endl;
		int i = 0;
		while (i<20)
		{
			if (!strcmp(users[i]->Getid(), ch))
			{
				currentUser = users[i];
				cout << users[i]->getfname() << " ";
				cout << users[i]->getlname();
				cout << " successfully set as Current User" << endl << endl;
				break;
			}
			i++;
		}
	}
	void setCurrentDate(int year1, int month1, int day1)
	{
		cout << endl << "Command :\t Set Current System Date ";
		cout << year1 << " " << month1 << " " << day1 << endl;
		currentDate = new Date;
		currentDate->setDate(year1, month1, day1);
		cout << "System Date :\t";
		currentDate->printDate();
		cout << endl << endl << endl;
	}
	void likePost(char* ch)
	{
		cout << endl << "Command:\tLikePost(" << ch << ")" << endl;
		int i = 0;
		while (i<11)
		{
			if (!strcmp(ch, post[i]->Getid()))
			{
				post[i]->AddLikes(currentUser);
				break;
			}
			i++;
		}
	}
	void printlikedByListofPost(char* ch)
	{
		cout << endl << "Command:\tViewLikedList(" << ch << ")" << endl;
		cout << endl << "Post Liked By :" << endl;
		int i = 0;
		while (i<11)
		{
			if (!strcmp(ch, post[i]->Getid()))
			{
				post[i]->printLikedbyList();
			}
			i++;
		}
		cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	void printTimelineofPage(char * ch)
	{
		cout << endl << "Commnd:\t ViewPage(" << ch << ")" << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
		int i = 0;
		while (i<12)
		{
			if (!strcmp(ch, page[i]->Getid()))
			{
				page[i]->printTimeLine();
				break;
			}
			i++;
		}
		cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	void printTimeline()
	{
		cout << "\nCommnd:\t View Timeline ";
		cout << endl << endl << "------------------------------------------------------------------------------------------------------------------" << endl << endl;
		cout << currentUser->getName() << "-TimeLine " << endl << endl;
		currentUser->printTimeLine();
		cout << endl << endl << "------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	void viewPost(char* ch)
	{
		cout << endl << "Command:\tViewPost(" << ch << ")" << endl << endl;
		int i = 0;
		while (i<11)
		{
			if (!strcmp(ch, post[i]->Getid()))
			{
				post[i]->print();
				break;
			}
			i++;
		}
		cout << endl << endl << "-------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	void sharePost(char* ch)
	{
		cout << endl << "Command:\tSharePost(" << ch << ")" << endl;
		int i = 0;
		while (i<11)
		{
			if (!strcmp(ch, post[i]->Getid()))
			{
				currentUser->SharePost(*post[i]);
				break;
			}
			i++;
		}
	}
	void postComment(char* ch, char* comment)
	{
		cout << endl << "Command:\tPostComment(" << ch << "," << comment << ")" << endl;
		int i = 0;
		while (i<11)
		{
			if (!strcmp(ch, post[i]->Getid()))
			{
				Comment* temp = new Comment;
				temp->setId("c13");
				temp->setcomment(comment);
				temp->setCommentUser(currentUser);
				post[i]->addComments(*temp);
				break;
			}
			i++;
		}
	}
	void search(char* ch)
	{
		cout << endl << "Command:\tSearch(" << ch << ")" << endl << endl;
		int j = 0;
		int i = 0;
		while (i<12)
		{
			if (Helper::searchString(page[i]->getName(), ch))
			{
				if (j == 0)
				{
					cout << "Pages:" << endl;
					j++;
				}
				cout << "---" << page[i]->Getid() << "-" << page[i]->getName() << endl;
			}
			i++;
		}
		j = 0;
		i = 0;
		while (i<11)
		{
			if (Helper::searchString(post[i]->getName(), ch))
			{
				if (j == 0)
				{
					cout << "Posts:" << endl;
					j++;
				}
				cout << "---" << post[i]->Getid() << "- \"" << post[i]->getName() << "\"\n";
			}
			i++;
		}
		j = 0;
		i = 0;
		while (i<20)
		{
			if (Helper::searchString(users[i]->getName(), ch))
			{
				if (j == 0)
				{
					cout << "Users:" << endl;
					j++;
				}
				cout << "---" << users[i]->Getid() << "-" << users[i]->getName() << endl;
			}
			i++;
		}
		cout << endl << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	~SocialNetworkApplication()
	{
		/*int i = 0;
		while(i<12)
		{
		if (comments[i] != 0)
		{
		delete comments[i];
		}
		i++;
		}
		delete[] comments;

		int j = 0;
		while (j<11)
		{
		if (post[j] != 0)
		{
		delete post[j];
		}
		j++;
		}
		delete[] post;
		*/
		int k = 0;
		while (k<20)
		{
			if (users[k] != 0)
			{
				delete users[k];
			}
			k++;
		}
		delete[] users;

		int l = 0;
		while (l<12)
		{
			if (page[l] != 0)
			{
				delete page[l];
			}
			l++;
		}
		delete[] page;
	}
	void execution()
	{
		setCurrentUser("u7");
		setCurrentDate(7, 8, 2018);
		currentUser->viewFriendList();
		currentUser->viewLikedPages();
		printlikedByListofPost("post5");
		printTimeline();
		printTimelineofPage("p1");
		currentUser->ViewHomePage();
		likePost("post5");
		printlikedByListofPost("post5");
		postComment("post4", "Good Luck for your Result");
		viewPost("post4");
		postComment("post8", "Thanks for the wishes");
		viewPost("post8");
		sharePost("post5");
		printTimeline();
		search("Birthday");
		search("Ali");
	}
};
void User::SharePost(Post & post)
{
	if (posts>10)
	{
		cout << endl;
		cout << " MAXIMUM LIMIT OF POSTS REACHED ";
		cout << endl;
	}
	else
	{
		if (timeLine == 0)
		{
			timeLine = new Post*[10];
			int i = 0;
			while (i<10)
			{
				timeLine[i] = 0;
				i++;
			}
		}
		Post* temp = new Post;
		char ch[5] = { posts };
		temp->setDescription(post.getName());
		temp->Setid(ch);
		temp->setDate(SocialNetworkApplication::getDate());
		timeLine[posts] = temp;
		posts++;
	}
}
void Page::printtimeline()
{
	int i = 0;
	while (i<posts)
	{
		if (timeline[i] != 0)
		{
			if ((timeline[i]->getDate()<SocialNetworkApplication::getDate() || SocialNetworkApplication::getDate() == timeline[i]->getDate()) && timeline[i] != 0)
			{
				cout << "---";
				cout << getName() << " shared ";
				timeline[i]->print();
			}
		}
		i++;
		cout << endl;
	}
}
void User::printtimeline()
{

	if (timeLine != 0)
	{
		int i = 0;
		while (i<posts)
		{
			if ((timeLine[i]->getDate()<SocialNetworkApplication::getDate() || SocialNetworkApplication::getDate() == timeLine[i]->getDate()) && timeLine[i] != 0)
			{
				cout << "---";
				cout << getName() << " Shared ";
				timeLine[i]->print();
			}
			i++;
			cout << endl;
		}
	}
}
Date *SocialNetworkApplication::currentDate = 0;
int main()
{
	SocialNetworkApplication app;
	app.filing();
	app.execution();
	system("pause");
	_getch();
}