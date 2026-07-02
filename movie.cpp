#include "movie.h"

void addMovie(vector<Movie>& movies)
{
    Movie m;

    cin.ignore();

    cout << "Enter Movie Title: ";
    getline(cin, m.title);

    cout << "Enter Genre: ";
    getline(cin, m.genre);

    cout << "Enter Rating (1-10): ";
    cin >> m.rating;

    movies.push_back(m);

    cout << "\nMovie Added Successfully!\n";
}

void displayMovies(vector<Movie>& movies)
{
    if(movies.empty())
    {
        cout << "\nNo Movies Available.\n";
        return;
    }

    cout << "\n===== Movie List =====\n";

    for(int i = 0; i < movies.size(); i++)
    {
        cout << "\nMovie " << i + 1 << endl;
        cout << "Title : " << movies[i].title << endl;
        cout << "Genre : " << movies[i].genre << endl;
        cout << "Rating: " << movies[i].rating << endl;
    }
}

void searchMovie(vector<Movie>& movies)
{
    if(movies.empty())
    {
        cout << "\nNo Movies Available.\n";
        return;
    }

    cin.ignore();

    string name;

    cout << "\nEnter Movie Title to Search: ";
    getline(cin, name);

    bool found = false;

    for(int i = 0; i < movies.size(); i++)
    {
        if(movies[i].title == name)
        {
            cout << "\nMovie Found!\n";
            cout << "Title : " << movies[i].title << endl;
            cout << "Genre : " << movies[i].genre << endl;
            cout << "Rating: " << movies[i].rating << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nMovie Not Found!\n";
    }
}
void recommendByGenre(vector<Movie>& movies)
{
    if(movies.empty())
    {
        cout << "\nNo Movies Available.\n";
        return;
    }

    cin.ignore();

    string genre;

    cout << "\nEnter Genre: ";
    getline(cin, genre);

    bool found = false;

    cout << "\n===== Recommended Movies =====\n";

    for(int i = 0; i < movies.size(); i++)
    {
        if(movies[i].genre == genre)
        {
            cout << "\nTitle : " << movies[i].title << endl;
            cout << "Genre : " << movies[i].genre << endl;
            cout << "Rating: " << movies[i].rating << endl;

            found = true;
        }
    }

    if(!found)
    {
        cout << "\nNo movies found in this genre.\n";
    }
}
void sortMoviesByRating(vector<Movie>& movies)
{
    if(movies.empty())
    {
        cout << "\nNo Movies Available.\n";
        return;
    }

    for(int i = 0; i < movies.size() - 1; i++)
    {
        for(int j = 0; j < movies.size() - i - 1; j++)
        {
            if(movies[j].rating < movies[j + 1].rating)
            {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }

    cout << "\nMovies Sorted by Rating Successfully!\n";
}
void deleteMovie(vector<Movie>& movies)
{
    if(movies.empty())
    {
        cout << "\nNo Movies Available.\n";
        return;
    }

    cin.ignore();

    string name;

    cout << "\nEnter Movie Title to Delete: ";
    getline(cin, name);

    for(int i = 0; i < movies.size(); i++)
    {
        if(movies[i].title == name)
        {
            movies.erase(movies.begin() + i);

            cout << "\nMovie Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nMovie Not Found!\n";
}
void saveMovies(vector<Movie>& movies)
{
    ofstream file("movies.txt");

    for(int i = 0; i < movies.size(); i++)
    {
        file << movies[i].title << endl;
        file << movies[i].genre << endl;
        file << movies[i].rating << endl;
    }

    file.close();

    cout << "\nMovies Saved Successfully!\n";
}
void loadMovies(vector<Movie>& movies)
{
    ifstream file("movies.txt");

    if(!file)
    {
        return;
    }

    Movie m;

    while(getline(file, m.title))
    {
        getline(file, m.genre);
        file >> m.rating;
        file.ignore();

        movies.push_back(m);
    }

    file.close();
}
void showTopRatedMovie(vector<Movie>& movies)
{
    if(movies.empty())
    {
        cout << "\nNo Movies Available.\n";
        return;
    }

    int maxIndex = 0;

    for(int i = 1; i < movies.size(); i++)
    {
        if(movies[i].rating > movies[maxIndex].rating)
        {
            maxIndex = i;
        }
    }

    cout << "\n===== Top Rated Movie =====\n";
    cout << "Title : " << movies[maxIndex].title << endl;
    cout << "Genre : " << movies[maxIndex].genre << endl;
    cout << "Rating: " << movies[maxIndex].rating << endl;
}