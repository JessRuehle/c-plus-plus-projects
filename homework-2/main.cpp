/**
 * Reads in data about student grades and provides statistics on data.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
 * Reads in the next string from in up until the next comma
 */
string readString(istream &istream)
{
    string word;
    char c;
    istream >> c;

    while (c != ',')
    {
        word += c;
        istream >> c;
    }

    return word;
}

/*
 * Finds the letter grade given a numerical grade.
 */
int findLetter(double avg)
{

    if (avg >+ 90)
    {
        return 0;
    }
    if (avg < 90 && avg >= 80 )
    {
        return 1;
    }
    if (avg < 80 && avg >= 70 )
    {
        return 2;
    }
    if (avg < 70 && avg >= 65 )
    {
        return 3;
    }
    return 4;
}

/*
 * Finds the adjusted total quiz grade after dropping lowest score..
 */
double findQuizTotal (double quizzes[])
{
    double drop = quizzes[0]; // lowest quiz to drop
    double total = 0; // totaled quizzes

    // go through all the quizzes
    for (int i = 0; i < 6; i++)
    {
        // find the lowest quiz to drop
        if (quizzes[i] < drop)
        {
            drop = quizzes[i];
        }

        // total all the quizzes
        total += quizzes[i];
    }

    // subtract the lowest quiz grade
    return total - drop;

}

/*
 * Finds a students final adjusted grade
 */
double findTotal(double data[])
{

    // start by totaling the quizzes
    double total = findQuizTotal(data);

    // add the exam grades to total
    for (int i = 6; i < 8; ++i)
    {
        total += data[i];
    }

    // return the total adjusted grade
    return total;
}

/*
 * Finds the highest quiz or exam grade.
 */
double findMax(double data[], bool isQuiz)
{
    double max;

    // if trying to find the max of quizzes, use this loop to iterate through the
    // indices that contain quiz data
    if (isQuiz)
    {
        for (int i = 0; i < 6; i++)
        {
            if (data[i] > max)
            {
                max = data[i];
            }
        }

    // if trying to find the max of exams, use this loop to iterate through the indices
    // that contain exam data

    } else
    {
        // if analyzing exams, use this loop.
        for (int i = 6; i < 8; i++)
        {
            if (data[i] > max)
            {
                max = data[i];
            }
        }
    }

    return max;
}


int main()
{

    ifstream in;
    ofstream out;
    in.open("inputfile.txt");
    out.open("outputfile.txt");

    int counter = 0; // counts the first line chars to know when to end
    char garb; // garbage char for commas

    // read in the header
    while (counter != 12) {
        string word = readString(in);
        out << left << setw(12 - word.length()) << word;
        counter++;
    }

    // add a newline at the end of the header
    out << endl;

    string word; // string to store id, lname, or fname
    double data[9]; // all grades per person
    double current; // stores the max of the current thing being calculated
    double maxQuiz = 0; // max quiz grade
    double maxExam = 0; // max exam grade
    double maxTotal = 0; // highest total grade
    double quizTotal = 0; // all adjusted quizzes
    double examTotal = 0; // all exams
    double total = 0; // all quizzes and exams after quiz drop
    double numStudents = 0; // total number of students
    double numQuizzes = 0; // total number of quizzes
    double numExams = 0; // total number of exams
    int letterGrades[5] = {0, 0, 0, 0, 0}; // number of letter grades

    // enter while loop to read rest of file
    while (!in.eof()) {

        numStudents++; // increment student count
        numQuizzes += 5; // increment 5 more quizzes
        numExams += 3; // increment 3 more exams

        // read in the first three strings
        for(int i = 0; i < 3; i++) {
            word = readString(in);
            out << left << setw(12 - word.length()) << word;
        }

        // read in the rest of the data about the quizzes and exams
        for (int i = 0; i < 9; ++i) {
            in >> data[i];
            in >> garb;
            out << right << setw(10) << data[i];
        }

        // find the max quiz
        current = findMax(data, true);
        if (current > maxQuiz) {
            maxQuiz = current;
        }

        // find the max exam
        current = findMax(data, false);
        if (current > maxExam) {
            maxExam = current;
        }

        // find the max average
        current = findTotal(data);
        total += current;
        if (current > maxTotal) {
            maxTotal = current;
        }

        quizTotal += findQuizTotal(data);
        examTotal += data[6];
        examTotal += data[7];
        examTotal += data[8];


        // find the letter grade of the student
        letterGrades[findLetter(current)]++;

        out << endl;

    }

    out << "The maximum of all the quizzes: " << maxQuiz << endl;
    out << "The average of all the quizzes: " << (quizTotal / numQuizzes) << endl;
    out << "The maximum of all the exams: " << maxExam << endl;
    out << "The average of all the exams: " << (examTotal / numExams) << endl;
    out << "The max of all the totals: " << maxTotal << endl;
    out << "The average of all the totals: " << (total / numStudents) << endl;
    out << "Number of As: " << letterGrades[0] << endl;
    out << "Number of Bs: " << letterGrades[1] << endl;
    out << "Number of Cs: " << letterGrades[2] << endl;
    out << "Number of Ds: " << letterGrades[3] << endl;
    out << "Number of Fs: " << letterGrades[4] << endl;

    return 0;
}
