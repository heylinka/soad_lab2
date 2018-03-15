#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <stdio.h>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//определение конца блока
bool End_Range (FILE * f)
{
  int tmp;
  tmp = fgetc(f);
  tmp = fgetc(f);
  if (tmp != '\'') fseek(f,-2,1);
  else fseek(f,1,1);
  return tmp == '\'' ? true : false;
}

int Simple_Merging_Sort (char *name)
{
  int a1, a2, k, i, j, kol;
  FILE *f, *f1, *f2;
  kol = 0;
  if ( (f = fopen(name,"r")) == NULL )
    printf("\nИсходный файл не может быть прочитан...");
  else
  {
    while ( !feof(f) )
      {
          fscanf(f,"%d",&a1);
          kol++;
      }
    fclose(f);
  }
  k = 1;
  while ( k < kol )
  {
    f = fopen(name,"r");
    f1 = fopen("smsort_1","w");
    f2 = fopen("smsort_2","w");
    if ( !feof(f) ) fscanf(f,"%d",&a1);
    while ( !feof(f) )
    {
      for ( i = 0; i < k && !feof(f) ; i++ )
      {
        fprintf(f1,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
      for ( j = 0; j < k && !feof(f) ; j++ )
      {
        fprintf(f2,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
    }
    fclose(f2);
    fclose(f1);
    fclose(f);

    f = fopen(name,"w");
    f1 = fopen("smsort_1","r");
    f2 = fopen("smsort_2","r");
    if ( !feof(f1) )
        fscanf(f1,"%d",&a1);
    if ( !feof(f2) )
        fscanf(f2,"%d",&a2);
    while ( !feof(f1) && !feof(f2) )
    {
      i = 0;
      j = 0;
      while ( i < k && j < k && !feof(f1) && !feof(f2) )
      {
        if ( a1 < a2 )
        {
          fprintf(f,"%d\n",a1);
          fscanf(f1,"%d",&a1);
          i++;
        }
        else
        {
          fprintf(f,"%d\n",a2);
          fscanf(f2,"%d",&a2);
          j++;
        }
      }
      while ( i < k && !feof(f1) )
      {
        fprintf(f,"%d\n",a1);
        fscanf(f1,"%d",&a1);
        i++;
      }
      while ( j < k && !feof(f2) )
      {
        fprintf(f,"%d\n",a2);
        fscanf(f2,"%d",&a2);
        j++;
      }
    }
    while ( !feof(f1) )
    {
      fprintf(f,"%d\n",a1);
      fscanf(f1,"%d",&a1);
    }
    while ( !feof(f2) )
    {
      fprintf(f,"%d\n",a2);
      fscanf(f2,"%d",&a2);
    }
    fclose(f2);
    fclose(f1);
    fclose(f);
    k *= 2;
  }
  remove("smsort_1");
  remove("smsort_2");
  return kol;
}

int Natural_Merging_Sort (char *name)
{
  int s1, s2, a0, kol, a1, a2, mark;
  FILE *f, *f1, *f2;
  s1 = s2 = 1;
  kol = 0;
  if ( (f = fopen(name,"r")) == NULL )
    printf("\nИсходный файл не может быть прочитан...");
  else
  {
    while ( !feof(f) )
      {
          fscanf(f,"%d",&a0);
          kol++;
      }
    fclose(f);
  }
  while ( s1 > 0 && s2 > 0 )
  {
    mark = 1;
    s1 = 0;
    s2 = 0;
    f = fopen(name,"r");
    f1 = fopen("nmsort_1","w");
    f2 = fopen("nmsort_2","w");
    fscanf(f,"%d",&a1);
    if ( !feof(f) )
      fprintf(f1,"%d\n",a1);
    if ( !feof(f) )
        fscanf(f,"%d",&a2);
    while ( !feof(f) )
    {
      if ( a2 < a1 )
      {
        switch (mark)
        {
          case 1:{fprintf(f1,"' "); mark = 2; s1++; break;}
          case 2:{fprintf(f2,"' "); mark = 1; s2++; break;}
        }
      }
      if ( mark == 1 )
      {
          fprintf(f1,"%d\n",a2);
          s1++;
      }
      else
      {
          fprintf(f2,"%d\n",a2);
          s2++;
      }
      a1 = a2;
      fscanf(f,"%d",&a2);
    }
    if ( s2 > 0 && mark == 2 )
    {
        fprintf(f2,"'");
    }
    if ( s1 > 0 && mark == 1 )
    {
        fprintf(f1,"'");
    }
    fclose(f2);
    fclose(f1);
    fclose(f);

    f = fopen(name,"w");
    f1 = fopen("nmsort_1","r");
    f2 = fopen("nmsort_2","r");
    if ( !feof(f1) )
        fscanf(f1,"%d",&a1);
    if ( !feof(f2) )
        fscanf(f2,"%d",&a2);
    bool file1, file2;
    while ( !feof(f1) && !feof(f2) )
    {
      file1 = file2 = false;
      while ( !file1 && !file2 )
      {
        if ( a1 <= a2 )
        {
          fprintf(f,"%d\n",a1);
          file1 = End_Range(f1);
          fscanf(f1,"%d",&a1);
        }
        else
        {
          fprintf(f,"%d\n",a2);
          file2 = End_Range(f2);
          fscanf(f2,"%d",&a2);
        }
      }
      while ( !file1 )
      {
        fprintf(f,"%d\n",a1);
        file1 = End_Range(f1);
        fscanf(f1,"%d",&a1);
      }
      while ( !file2 )
      {
        fprintf(f,"%d\n",a2);
        file2 = End_Range(f2);
        fscanf(f2,"%d",&a2);
      }
    }
    file1 = file2 = false;
    while ( !file1 && !feof(f1) )
    {
      fprintf(f,"%d\n",a1);
      file1 = End_Range(f1);
      fscanf(f1,"%d",&a1);
    }
    while ( !file2 && !feof(f2) )
    {
      fprintf(f,"%d\n",a2);
      file2 = End_Range(f2);
      fscanf(f2,"%d",&a2);
    }
    fclose(f2);
    fclose(f1);
    fclose(f);
  }
  remove("nmsort_1");
  remove("nmsort_2");
  return kol;
}

int Multiway_Merging_Sort (char *name)
{
  int a1, a2, a3, k, i, j, m, kol;
  FILE *f, *f1, *f2, *f3;
  kol = 0;
  if ( (f = fopen(name,"r")) == NULL )
    printf("\nИсходный файл не может быть прочитан...");
  else
  {
    while ( !feof(f) )
      {
          fscanf(f,"%d",&a1);
          kol++;
      }
    fclose(f);
  }
  k = 1;
  while ( k < kol )
  {
    f = fopen(name,"r");
    f1 = fopen("smsort_1","w");
    f2 = fopen("smsort_2","w");
    f3 = fopen("smsort_3","w");
    if ( !feof(f) ) fscanf(f,"%d",&a1);
    while ( !feof(f) )
    {
      for ( i = 0; i < k && !feof(f) ; i++ )
      {
        fprintf(f1,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
      for ( j = 0; j < k && !feof(f) ; j++ )
      {
        fprintf(f2,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
      for ( m = 0; m < k && !feof(f) ; m++ )
      {
        fprintf(f3,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
    }
    fclose(f3);
    fclose(f2);
    fclose(f1);
    fclose(f);

    f = fopen(name,"w");
    f1 = fopen("smsort_1","r");
    f2 = fopen("smsort_2","r");
    f3 = fopen("smsort_3","r");
    if ( !feof(f1) )
        fscanf(f1,"%d",&a1);
    if ( !feof(f2) )
        fscanf(f2,"%d",&a2);
    if ( !feof(f3) )
        fscanf(f3,"%d",&a3);
    while ( !feof(f1) && !feof(f2) && !feof(f3) )
    {
      i = 0;
      j = 0;
      m = 0;
      while ( i < k && j < k && m < k &&
              !feof(f1) && !feof(f2) && !feof(f3))
      {
         if (a1 < a2 && a2 < a3 && a1 < a3) //a1, a2, a3
         {
             fprintf(f,"%d\n",a1);
             fscanf(f1,"%d",&a1);
             i++;
             fprintf(f,"%d\n",a2);
             fscanf(f2,"%d",&a2);
             j++;
         }
         else if (a1 < a2 && a3 < a2 && a1 < a3) //a1, a3, a2
         {
             fprintf(f,"%d\n",a1);
             fscanf(f1,"%d",&a1);
             i++;
             fprintf(f,"%d\n",a3);
             fscanf(f3,"%d",&a3);
             m++;
         }
         else if (a2 < a1 && a1 < a3 && a2 < a3) //a2, a1, a3
         {
             fprintf(f,"%d\n",a2);
             fscanf(f2,"%d",&a2);
             j++;
             fprintf(f,"%d\n",a1);
             fscanf(f1,"%d",&a1);
             i++;
         }
         else if (a2 < a1 && a3 < a1 && a2 < a3) //a2, a3, a1
         {
             fprintf(f,"%d\n",a2);
             fscanf(f2,"%d",&a2);
             j++;
             fprintf(f,"%d\n",a3);
             fscanf(f3,"%d",&a3);
             m++;
         }
         else if (a3 < a1 && a1 < a2 && a3 < a2) //a3, a1, a2
         {
             fprintf(f,"%d\n",a3);
             fscanf(f3,"%d",&a3);
             m++;
             fprintf(f,"%d\n",a1);
             fscanf(f1,"%d",&a1);
             i++;
         }
         else if (a2 < a1 && a3 < a2 && a3 < a1) //a3, a2, a1
         {
             fprintf(f,"%d\n",a3);
             fscanf(f3,"%d",&a3);
             m++;
             fprintf(f,"%d\n",a2);
             fscanf(f2,"%d",&a2);
             j++;
         }
      }
      while ( i < k && !feof(f1) )
      {
        fprintf(f,"%d\n",a1);
        fscanf(f1,"%d",&a1);
        i++;
      }
      while ( j < k && !feof(f2) )
      {
        fprintf(f,"%d\n",a2);
        fscanf(f2,"%d",&a2);
        j++;
      }
      while ( m < k && !feof(f3) )
      {
        fprintf(f,"%d\n",a3);
        fscanf(f3,"%d",&a3);
        m++;
      }
    }
    while ( !feof(f1) )
    {
      fprintf(f,"%d\n",a1);
      fscanf(f1,"%d",&a1);
    }
    while ( !feof(f2) )
    {
      fprintf(f,"%d\n",a2);
      fscanf(f2,"%d",&a2);
    }
    while ( !feof(f3) )
    {
      fprintf(f,"%d\n",a3);
      fscanf(f3,"%d",&a3);
    }
    fclose(f3);
    fclose(f2);
    fclose(f1);
    fclose(f);
    k *= 3;
  }
  remove("smsort_1");
  remove("smsort_2");
  remove("smsort_3");
  return kol;
}

void MainWindow::on_pushLoad_clicked()
{
    //отображение входных данных в окне приложени¤
    QFile file("C://Qt//qtcreator-2.0.1//Lab2_SAOD_test//dataNum.txt");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "Information", "File can not be opened!");
    QTextStream in(&file);
    ui->textInput->setText((in.readAll()));
}

void MainWindow::on_pushDone_clicked()
{
    if(!ui->radioSimple->isChecked() && !ui->radioNatural->isChecked())
    {
        QMessageBox::warning(this, "Warning","Incorrect! Please, choose one type of sort!");
    }
    //проверка: выбран метод простого слияния
    else if(ui->radioSimple->isChecked())
        {
            char *name = "C://Qt//qtcreator-2.0.1//Lab2_SAOD_test//dataNum1.txt";
            clock_t start = clock();
            int n = Simple_Merging_Sort(name);
            clock_t end = clock();
            double simpleTime = double(end - start)/CLOCKS_PER_SEC;
            ui->txtSimpleT->setText(QString::number(simpleTime, 'f', 3));
            ui->txtSimpleN->setText(QString::number(n));;

            QFile file("C://Qt//qtcreator-2.0.1//Lab2_SAOD_test//dataNum1.txt");
            if (!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0, "Information", "File can not be opened!");
            QTextStream out(&file);
            ui->textOutput->setText((out.readAll()));
        }
    else if(ui->radioNatural->isChecked())
        {
            char *name = "C://Qt//qtcreator-2.0.1//Lab2_SAOD_test//dataNum2.txt";
            clock_t start = clock();
            int n = Natural_Merging_Sort(name);
            clock_t end = clock();
            double naturalTime = double(end - start)/CLOCKS_PER_SEC;
            ui->txtNaturalT->setText(QString::number(naturalTime, 'f', 3));
            ui->txtNaturalN->setText(QString::number(n));;

            QFile file("C://Qt//qtcreator-2.0.1//Lab2_SAOD_test//dataNum2.txt");
            if (!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0, "Information", "File can not be opened!");
            QTextStream out(&file);
            ui->textOutput->setText((out.readAll()));
        }
    /*
    else if(ui->radioSort->isChecked())
        {
            char *name = "C://Qt//qtcreator-2.0.1//Lab2_SAOD_test//data.txt";
            clock_t start = clock();
            int n = Multiway_Merging_Sort(name);
            clock_t end = clock();
            double multiTime = double(end - start)/CLOCKS_PER_SEC;
            ui->txtMultiT->setText(QString::number(multiTime, 'f', 3));
            ui->txtMultiN->setText(QString::number(n));;

            QFile file("C://Qt//qtcreator-2.0.1//Lab2_SAOD_test//data.txt");
            if (!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0, "Information", "File can not be opened!");
            QTextStream out(&file);
            ui->textOutput->setText((out.readAll()));
        }
    */
}
