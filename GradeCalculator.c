#include <stdio.h>

int main(void) {

    //Weekly Labs Variables

    const float weeklyLabsTotalMarks = 100.0;
    const float weeklyLabsWeight = 0.1;
    float weeklyLabsWeightPrint;
    float weeklyLabsMarksEarned;
    float weeklyLabsYourMark;

    //Daily Practice Variables

    const float dailyPracticeTotalMarks = 100.0;
    const float dailyPracticeWeight = 0.1;
    float dailyPracticeWeightPrint;
    float dailyPracticeMarksEarned;
    float dailyPracticeYourMark;

    //Lab Exam 1 Variables

    const float labExam1TotalMarks = 100.0;
    const float labExam1Weight = 0.1;
    float labExam1WeightPrint;
    float labExam1MarksEarned;
    float labExam1YourMark;

    //Lab Exam 2 Variables

    const float labExam2TotalMarks = 100.0;
    const float labExam2Weight = 0.1;
    float labExam2WeightPrint;
    float labExam2MarksEarned;
    float labExam2YourMark;

    //Bonus From Lab Exams

    int bonusLabExam = 0;

    //Assignment 1 Variables

    const float a1TotalMarks = 100.0;
    const float a1Weight = 0.05;
    float a1WeightPrint;
    float a1MarksEarned;
    float a1YourMark;

    //A1 MOSS Variables

    int a1MOSS;

    //Assignment 2 Variable

    const float a2TotalMarks = 100.0;
    const float a2Weight = 0.1;
    float a2WeightPrint;
    float  a2MarksEarned;
    float a2YourMark;

    //A2 MOSS Variables

    int a2MOSS;

    //Assignment 3 Variables

    const float a3TotalMarks = 100.0;
    const float a3Weight = 0.1;
    float a3WeightPrint;
    float a3MarksEarned;
    float a3YourMark;

    //A3 MOSS Variables

    int a3MOSS;

    //Desired Grade Variables

    float desiredGrade;
    float desiredGradePercent;

    //Course Mark Variables

    float currentCourseMark;
    const float totalCourseMarks = 65.0;
    const float courseWeight = 0.65;
    float currentCourseMarkPercent;

    //Final Exam Variables

    const float examTotalMarks = 100.00;
    float examWeightPrint;
    float examGradeNeeded;
    const float examMarks = 35.0;
    float examPercentNeeded;
    const float examWeight= 0.35;

    //Input Marks

    printf("\nEnter the following marks (each out of 100):\n");
    printf("\n");

    //Weekly Labs Input

    printf("Weekly Labs: ");
    scanf("%f", &weeklyLabsMarksEarned);
    printf("\n");

    if ( (weeklyLabsMarksEarned > 100) || (weeklyLabsMarksEarned < 0) ) {
        printf("Marks cannot be greater than 100 or less than 0.\nTry Again.\n");
        printf("Weekly Labs: ");
        scanf("%f", &weeklyLabsMarksEarned);
        printf("\n");
        weeklyLabsYourMark = weeklyLabsMarksEarned;
    }
    else {
        weeklyLabsYourMark = weeklyLabsMarksEarned;
    }

    //Daily Practice Input

    printf("Daily Practice: ");
    scanf("%f", &dailyPracticeMarksEarned);
    printf("\n");

    if ( (dailyPracticeMarksEarned > 100) || (dailyPracticeMarksEarned < 0) ) {
        printf("Marks cannot be greater than 100 or less than 0.\nTry Again.\n");
        printf("Daily Practice: ");
        scanf("%f", &dailyPracticeMarksEarned);
        printf("\n");
        dailyPracticeYourMark = dailyPracticeMarksEarned;
    }
    else {
        dailyPracticeYourMark = dailyPracticeMarksEarned;
    }

    //Lab Exam 1 Input

    printf("Lab Exam 1: ");
    scanf("%f", &labExam1MarksEarned);
    printf("\n");

    if ( (labExam1MarksEarned > 100) || (labExam1MarksEarned < 0) ) {
        printf("Marks cannot be greater than 100 or less than 0.\nTry again.\n");
        printf("Lab Exam 1: ");
        scanf("%f", &labExam1MarksEarned);
        printf("\n");
        labExam1YourMark = labExam1MarksEarned;
    }
    else {
        labExam1YourMark = labExam1MarksEarned;
    }

    //Lab Exam 2 Input

    printf("Lab Exam 2: ");
    scanf("%f", &labExam2MarksEarned);
    printf("\n");

    if ( (labExam2MarksEarned > 100) || (labExam2MarksEarned < 0) ) {
        printf("Marks cannot be greater than 100 or less than 0.\nTry Again.\n");
        printf("Lab Exam 2: ");
        scanf("%f", &labExam2MarksEarned);
        printf("\n");
        labExam2YourMark = labExam2MarksEarned;
    }
    else {
        labExam2YourMark = labExam2MarksEarned;
    }

    //Assignment 1 Input

    printf("Assignment 1: ");
    scanf("%f", &a1MarksEarned);
    printf("\n");

    if ( (a1MarksEarned > 100) || (a1MarksEarned < 0) ) {
        printf("Marks cannot be greater than 100 or less than 0.\nTry Again.\n");
        printf("Assignment 1: ");
        scanf("%f", &a1MarksEarned);
        printf("\n");
        a1YourMark = a1MarksEarned;
    }

    //A1 MOSS Input

    printf("Assignment 1 MOSS Output: ");
    scanf("%d", &a1MOSS);
    printf("\n");
    if ( (a1MOSS > 1) || (a1MOSS < 0) ) {
        printf("MOSS cannot be greater than 1 or less than 0.\nTry Again.\n");
        printf("Assignment 1 MOSS Output: ");
        scanf("%d", &a1MOSS);
        printf("\n");
    }
    else if (a1MOSS == 0) {
        a1YourMark = 0;
    }
    else {
        a1YourMark = a1MarksEarned;
    }

    //Assignment 2 Input

    printf("Assignment 2: ");
    scanf("%f", &a2MarksEarned);
    printf("\n");

    if ( (a2MarksEarned > 100) || (a2MarksEarned < 0) ) {
        printf("Marks cannot be greater than 100 or less than 0.\nTry Again.\n");
        printf("Assignment 2: ");
        scanf("%f", &a2MarksEarned);
        printf("\n");
        a2YourMark = a2MarksEarned;
    }

    //A2 MOSS Input

    printf("Assignment 2 MOSS Output: ");
    scanf("%d", &a2MOSS);
    printf("\n");

    if ( (a2MOSS > 1) || (a2MOSS < 0) ) {
        printf("MOSS cannot be greater than 1 or less than 0.\nTry Again.\n");
        printf("Assignment 2 MOSS Output: ");
        scanf("%d", &a2MOSS);
        printf("\n");
    }
    else if (a2MOSS == 0) {
        a2YourMark = 0;
        a2MarksEarned = a2YourMark;
    }
    else {
        a2YourMark = a2MarksEarned;
    }

    //Assignment 3 Input

    printf("Assignment 3: ");
    scanf("%f", &a3MarksEarned);
    printf("\n");

    if ( (a3MarksEarned > 100) || (a3MarksEarned < 0) ) {
        printf("Marks cannot be greater than 100 or less than 0.\nTry Again.\n");
        printf("Assignment 3: ");
        scanf("%f", &a3MarksEarned);
        printf("\n");
        a3YourMark = a3MarksEarned;
    }

    //A3 MOSS Input

    printf("Assignment 3 MOSS Output: ");
    scanf("%d", &a3MOSS);
    printf("\n");

    if ( (a3MOSS > 1) || (a3MOSS < 0) ) {
        printf("MOSS cannot be greater than 1 or less than 0.\nTry Again.\n");
        printf("Assignment 3 MOSS Output: ");
        scanf("%d", &a3MOSS);
        printf("\n");
    }
    else if (a3MOSS == 0) {
        a3YourMark = 0;
    }
    else {
        a3YourMark = a3MarksEarned;
    }

    //Desired Grade Input

    printf("How Much Do You Desire for an Overall Course Grade: ");
    scanf("%f", &desiredGrade);
    printf("\n");

    if ( (desiredGrade > 100) || (desiredGrade < 0) ) {
        printf("Marks cannot be greater than 100 or less than 0.\nTry Again.\n");
        printf("How Much Do You Desire for an Overall Course Grade: ");
        scanf("%f", &desiredGrade);
        printf("\n");
    }

    //Header

    printf("\n**********************************************************************\n");
    printf("Assessment \t \t  Weight in Percent \t \t Marks\n");
    printf("----------------------------------------------------------------------\n");


    //Weekly Labs Print

    printf("Weekly Labs \t \t \t ");

    weeklyLabsWeightPrint = weeklyLabsWeight * weeklyLabsTotalMarks;
    printf("%.0f \t \t \t ", weeklyLabsWeightPrint);

    printf("%.2f\n", weeklyLabsYourMark);

    weeklyLabsYourMark = weeklyLabsMarksEarned * weeklyLabsWeight;

    //Daily  Practice Print

    printf("Daily Practice \t \t \t ");

    dailyPracticeWeightPrint = dailyPracticeWeight * dailyPracticeTotalMarks;
    printf("%.0f \t \t \t ", dailyPracticeWeightPrint);

    printf("%.2f\n", dailyPracticeYourMark);

    dailyPracticeYourMark = dailyPracticeMarksEarned * dailyPracticeWeight;

    //Lab Exam 1 Print

    printf("Lab Exam 1 \t \t \t ");

    labExam1WeightPrint = labExam1Weight * labExam1TotalMarks;
    printf("%.0f \t \t \t ", labExam1WeightPrint);

    printf("%.2f\n", labExam1YourMark);

    labExam1YourMark = labExam1MarksEarned * labExam1Weight;

    //Lab Exam 2 Print

    printf("Lab Exam 2 \t \t \t ");

    labExam2WeightPrint = labExam2Weight * labExam2TotalMarks;
    printf("%.0f \t \t \t ", labExam2WeightPrint);

    printf("%.2f\n", labExam2YourMark);

    labExam2YourMark = labExam2MarksEarned * labExam2Weight;

    //Bonus From Lab Exams Print

    printf("Bonus from Lab Exams: ");

    if ( (labExam1MarksEarned == 100) && (labExam2MarksEarned == 100) ) {
        bonusLabExam = 3;
    }
    else {
        bonusLabExam = 0;
    }

    printf("%d\n", bonusLabExam);

    //Assignment 1 Print

    printf("Assignment 1 \t \t \t ");

    a1WeightPrint = a1Weight * a1TotalMarks;
    printf("%.0f \t \t \t ", a1WeightPrint);

    printf("%.2f\n", a1YourMark);

    a1YourMark = a1MarksEarned * a1Weight;

    //Assignment 2 Print

    printf("Assignment 2 \t \t \t ");

    a2WeightPrint = a2Weight * a2TotalMarks;
    printf("%.0f \t \t \t ", a2WeightPrint);

    printf("%.2f\n", a2YourMark);

    a2YourMark = a2MarksEarned * a2Weight;

    //Assignment 3 Print

    printf("Assignment 3 \t \t \t ");

    a3WeightPrint = a3Weight * a3TotalMarks;
    printf("%.0f \t \t \t ", a3WeightPrint);

    printf("%.2f\n", a3YourMark);

    a3YourMark = a3MarksEarned * a3Weight;

    //Final Exam Print

    printf("Final Exam \t \t \t ");

    examWeightPrint = examWeight * examTotalMarks;
    printf("%.0f \t \t \t", examWeightPrint);

    printf("To Be Determined");

    //Footer

    printf("\n***********************************************************************\n");

    //Current Course Mark Print

    currentCourseMark = weeklyLabsYourMark + dailyPracticeYourMark + labExam1YourMark + labExam2YourMark + bonusLabExam + a1YourMark + a2YourMark + a3YourMark;

    printf("Current Course Mark = ");
    printf("%.2f / %.2f\n", currentCourseMark, totalCourseMarks);

    currentCourseMarkPercent = currentCourseMark / totalCourseMarks;

    //Desired Grade

    desiredGradePercent = desiredGrade / 100;

    //Goal Print

    examGradeNeeded = ( ((courseWeight * currentCourseMarkPercent) - desiredGradePercent) / (-examWeight) ) * 100;
    examGradeNeeded = examGradeNeeded * examWeight;

    printf("You need %.2f / %.2f to reach your goal (%.0f)\n", examGradeNeeded, examMarks, desiredGrade);

    examPercentNeeded = examGradeNeeded / examWeight;

    printf("In percentage, you need %.0f percent to reach your goal (%.0f)\n", examPercentNeeded, desiredGrade);

    //MOSS

    if ( (a1MOSS == 0) && (a2MOSS == 0) && (a3MOSS == 0) ) {
        printf("\n***************************************************\n");
        printf("You cannot pass the course - try harder next time.\n");
        printf("***************************************************\n");
    }


return 0;

}
