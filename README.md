# Social-Network-Application
A console based social network application devloped on C++.

# Tools & Applications
- Visual Studio
- C++

# Description
Each User in the application has a unique ID and name. He may have other users in his friend list, having 10 friends at max. He has a list of pages which he has liked (10 pages at max). Each Page has a unique ID, title, list of posts it has shared and total number of people who have liked it. Each Post has a unique ID, description, no of likes, list of people who have liked it and shared date for example; a post is shared at 25th October 2017. A user or a page can share 10 posts at max. A post can have 10 comments at max. A comment is posted by a specific user/page. User can delete a comment on his posts. All the Users, Pages and Posts in the application are objects having IDs.

# Functionalities
- ### Set Current User
a.	Asks user about his ID and set him as current user of application. Now everything that we see in the system will be view of this user.
- ### View Home of Current User
a.	Display posts of all friends shared in last 24 hours. For example,
![image](https://user-images.githubusercontent.com/85407775/120929405-5c758600-c702-11eb-8fc9-5d5fcc805aed.png)

b.	Display posts of all his liked pages (or communities) shared in last 24 hours. For example 
![image](https://user-images.githubusercontent.com/85407775/120929461-88910700-c702-11eb-8379-dadebf1409a1.png)
- ### Like a Post
a.	Ask user about ID of post and like it. A post can be liked by 10 users at max.
- ### View the List of People who Liked a Post
a.	Take Post ID from user and display list of people who have liked it
- ### Comment on a Post
a.	Take post ID and comment from the user and add this comment in the post
