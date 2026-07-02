#include "movie.h"

int main()
{
    vector<Movie> movies;
    loadMovies(movies);

    int choice;

    do
    {
        cout << "\n==============================\n";
        cout << " Movie Recommendation System\n";
        cout << "==============================\n";
        cout << "1. Add Movie\n";
        cout << "2. Display Movies\n";
        cout << "3. Search Movie\n";
        cout << "4. Recommend by Genre\n";
        cout << "5. Sort Movies by Rating\n";
        cout << "6. Delete Movie\n";
        cout << "7. Show Top Rated Movie\n";
        cout << "8. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addMovie(movies);
                break;

            case 2:
                displayMovies(movies);
                break;

            case 3:
                searchMovie(movies);
                break;

            case 4:
                recommendByGenre(movies);
                break;

            case 5:
                sortMoviesByRating(movies);
                break;

            case 6:
                deleteMovie(movies);
                break;

            case 7:
                showTopRatedMovie(movies);
                break;

            case 8:
                saveMovies(movies);
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while(choice != 8);

    return 0;
}