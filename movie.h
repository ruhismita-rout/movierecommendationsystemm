#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Movie
{
    string title;
    string genre;
    float rating;
};
void addMovie(vector<Movie>& movies);
void displayMovies(vector<Movie>& movies);
void searchMovie(vector<Movie>& movies);
void recommendByGenre(vector<Movie>& movies);
void sortMoviesByRating(vector<Movie>& movies);
void deleteMovie(vector<Movie>& movies);
void saveMovies(vector<Movie>& movies);
void loadMovies(vector<Movie>& movies);
void showTopRatedMovie(vector<Movie>& movies);


#endif