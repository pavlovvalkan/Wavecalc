#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "helpdialog.h"
#include "about.h"
#include "qvalidator.h"
#include <QMessageBox>



//global varialble for speed of wave in m/s
float SpeedOfWave=343;
//global variable for wavelength (λ)
float Lambda=0;
//global variable for frequency
float Frequency=0;
//global variable for Farfield border
float Farfield=0;
//global variable for Antenna size
float Distance=0;
//global variable for Presentage
int Presentage=0;
//global variable for Steps
int Steps=0;

std::string Array[4][50];

void DLR (Ui::MainWindow *ui,int lSteps, float lLambda, int LPresentage);
void RLD (Ui::MainWindow *ui,int lSteps, float lLambda, int LPresentage);
void LDR (Ui::MainWindow *ui,int lSteps, float lDistance, int LPresentage);
void RDL (Ui::MainWindow *ui,int lSteps, float lDistance, int LPresentage);
void DRL (Ui::MainWindow *ui,int lSteps, float lFarfield, int LPresentage);
void LRD (Ui::MainWindow *ui,int lSteps, float lFarfield, int LPresentage);


void UiUpdate (Ui::MainWindow *ui);
float wavelengthCalc (float Lfrequency);
float SetFrequency (float Lfrequency);
float SetDistance (float Ldistance);
void FarfieldCalc();
void popTableWidget (Ui::MainWindow *ui, std::string lArray[4][50 ]);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Set frequency slider
void MainWindow::on_horizontalSlider_Frq_sliderReleased()
{
    //Set frequency
    Frequency= SetFrequency((float)ui->horizontalSlider_Frq->value());
    Lambda=wavelengthCalc(Frequency);
    FarfieldCalc();

    //Update values
    UiUpdate(ui);
}

//Obsolate slot
void MainWindow::on_horizontalSlider_Frq_valueChanged(int value)
{/*
    //Set frequency
    Frequency= SetFrequency(ui->horizontalSlider_Frq->value());
    //Set frequency box(line edit)
    ui->lineEdit_Freq->setText(QString::number(ui->horizontalSlider_Frq->value()));
    //Set Lambda value using frequency line edit
    Lambda=wavelengthCalc(ui->lineEdit_Freq->text().toFloat());
    //Set  Lambda box (line edit) value
    ui->lineEdit_Lambda->setText(QString::number(Lambda));*/
}


//Frequency line edit
void MainWindow::on_lineEdit_Freq_returnPressed()
{
    //Data input validate
    QDoubleValidator *doubleValidator = new QDoubleValidator(0.0, 10000.0, 5, this);
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_Freq->setValidator(doubleValidator);

    //Set frequency
    Frequency= SetFrequency(ui->lineEdit_Freq->text().toFloat());

    //Update Lambda:
    Lambda=wavelengthCalc(Frequency);

    FarfieldCalc();

    //Update values
    UiUpdate(ui);
}



//Set wavelength
void MainWindow::on_lineEdit_Lambda_returnPressed()
{

    Lambda=ui->lineEdit_Lambda->text().toFloat();
    //Calculate frequency
    Frequency=SpeedOfWave/Lambda;

    FarfieldCalc();

    //Update values
    UiUpdate(ui);

}

//Slider adjust
void MainWindow::on_horizontalSlider_Farfield_sliderReleased()
{

    Farfield=ui->horizontalSlider_Farfield->value();

    //Update values
    UiUpdate(ui);


}
//Obsolate slot
void MainWindow::on_horizontalSlider_Farfield_valueChanged(int value)
{/*
    Farfield=ui->horizontalSlider_Farfield->value();
    //Update the line edit
    ui->lineEdit_Farfield->setText(QString::number(Farfield));*/
}

void MainWindow::on_lineEdit_Farfield_returnPressed()
{
    //Data input validate
    QDoubleValidator *doubleValidator = new QDoubleValidator(0.0, 15.0, 5, this);
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_Farfield->setValidator(doubleValidator);

    //Set farfield
    Farfield=ui->lineEdit_Farfield->text().toFloat();

    //Update values
    UiUpdate(ui);
}

void MainWindow::on_horizontalSlider_Distnce_sliderReleased()
{
    Distance=SetDistance((float)ui->horizontalSlider_Distnce->value()/100);

    FarfieldCalc();

    //Update values
    UiUpdate(ui);
}

void MainWindow::on_lineEdit_Distance_returnPressed()
{
    //Data input validate
    QDoubleValidator *doubleValidator = new QDoubleValidator(0.0, 5, 5, this);
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_Farfield->setValidator(doubleValidator);

    //Set distance
    Distance=ui->lineEdit_Distance->text().toFloat();

    FarfieldCalc();

    //Update values
    UiUpdate(ui);


}

void MainWindow::on_lineEdit_SpeedOfSound_returnPressed()
{
    //Data input validate
    QDoubleValidator *doubleValidator = new QDoubleValidator(0.0, 400, 5, this);
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_SpeedOfWave->setValidator(doubleValidator);

    //Set Speed of sound
    SpeedOfWave=ui->lineEdit_SpeedOfWave->text().toFloat();

    //Update Lambda
    Lambda=SpeedOfWave/Frequency;

    //Update values
    UiUpdate(ui);;


}


void UiUpdate (Ui::MainWindow *ui)
{
    ui->lineEdit_Freq->setText(QString::number(Frequency));
    ui->lineEdit_Lambda->setText(QString::number(Lambda));
    ui->lineEdit_SpeedOfWave->setText(QString::number(SpeedOfWave));
    ui->lineEdit_Farfield->setText(QString::number(Farfield));
    ui->lineEdit_Distance->setText(QString::number(Distance));

    ui->horizontalSlider_Frq->setValue((int)Frequency);
    ui->horizontalSlider_Distnce->setValue(Distance*100);
    ui->horizontalSlider_Farfield->setValue((int)Farfield);
}


float wavelengthCalc (float Lfrequency){
    return SpeedOfWave/Lfrequency;

}

float SetFrequency (float Lfrequency){
    return Lfrequency;
}

float SetDistance (float Ldistance){
    return Ldistance;
}

void MainWindow::on_horizontalSlider_3_sliderReleased()
{

}

void MainWindow::on_horizontalSlider_Distance_sliderReleased()
{

}

void FarfieldCalc(){

    Farfield = (2*pow(Distance,2))/Lambda;
}




void MainWindow::on_comboBox_Fix_currentIndexChanged(int index)
{

}


void MainWindow::on_pushButton_clicked()
{

        //Get Presentage and Steps values from spin boxes
        Presentage=ui->spinBox_Precentage->value();
        Steps=ui->spinBox_Steps->value();
        // Retrieve selected indexes from both combo boxes
        int fixIndex = ui->comboBox_Fix->currentIndex();
        int holdIndex = ui->comboBox_Hold->currentIndex();

        // Generate a unique identifier based on the indexes
        int combinationId = fixIndex * 3 + holdIndex;  // Assumes 3 possible states per combo box

        // Handle different combinations using a switch-case statement
        switch (combinationId)
        {
        case 0:
            //QMessageBox::information(this, "Combination", "Fix: State 1, Hold: State 1");
            QMessageBox::warning(this, "Invalid combination", "\"Fix\" and \"Hold\" cannot have the same state.");
            break;
        case 1:
            //QMessageBox::information(this, "Combination", "Fix: State 1, Hold: State 2");
            LRD (ui, Steps, Farfield,Presentage);
            break;
        case 2:
            //QMessageBox::information(this, "Combination", "Fix: State 1, Hold: State 3");
            LDR(ui, Steps, Distance,Presentage);
            break;
        case 3:
           // QMessageBox::information(this, "Combination", "Fix: State 2, Hold: State 1");
            RLD (ui, Steps, Lambda,Presentage);
            break;
        case 4:
            //QMessageBox::information(this, "Combination", "Fix: State 2, Hold: State 2");
            QMessageBox::warning(this, "Invalid combination", "\"Fix\" and \"Hold\" cannot have the same state.");
            break;
        case 5:
            //QMessageBox::information(this, "Combination", "Fix: State 2, Hold: State 3");
            RDL (ui, Steps, Distance,Presentage);
            break;
        case 6:
           // QMessageBox::information(this, "Combination", "Fix: State 3, Hold: State 1");
            DLR(ui, Steps, Lambda,Presentage);
            break;
        case 7:
            //QMessageBox::information(this, "Combination", "Fix: State 3, Hold: State 2");
            DRL (ui, Steps, Farfield, Presentage);
            break;
        case 8:
            //QMessageBox::information(this, "Combination", "Fix: State 3, Hold: State 3");
            QMessageBox::warning(this, "Invalid combination", "\"Fix\" and \"Hold\" cannot have the same state.");
            break;
        default:
            QMessageBox::warning(this, "Unexpected Case", "An unexpected combination was selected.");
            break;
        }
        popTableWidget(ui, Array);
}

// fix R hold D calc L
void RDL (Ui::MainWindow *ui,int lSteps, float lDistance, int LPresentage)
{

    float lDistance_min=lDistance-(float)LPresentage/100*lDistance;
    float lDistance_max=lDistance+(float)LPresentage/100*lDistance;
    float lStepValue=(lDistance_max-lDistance_min) / (lSteps-1);

    // // Convert floats to QString
    // QString message = "lDistance_min: " + QString::number(lDistance_min) +
    //                   "lDistance_max: " + QString::number(lDistance_max);
    // QMessageBox::information(ui->pushButton, "Combination", message);

    for (int i = 0;i < Steps; i++) {
        lDistance=lDistance_min + i*lStepValue;
        //QMessageBox::information(ui->pushButton, "Distance", QString::number(lDistance));
        Lambda = (2 * pow(lDistance, 2)) / Farfield;
        //QMessageBox::information(ui->pushButton, "Lambda", QString::number(Lambda));
        Array[0][i]=std::to_string(Farfield);
        Array[1][i]=std::to_string(lDistance);
        Array[2][i]=std::to_string(Lambda);
    }
}




// fix R hold L calc D
void RLD (Ui::MainWindow *ui,int lSteps, float lLambda, int LPresentage)
{

    float lLambda_min=lLambda-(float)LPresentage/100*lLambda;
    float lLambda_max=lLambda+(float)LPresentage/100*lLambda;
    float lStepValue=(lLambda_max-lLambda_min) / (lSteps-1);

    // // Convert floats to QString
    // QString message = "lLambda_min: " + QString::number(lLambda_min) +
    //                   "\nlLambda_max: " + QString::number(lLambda_max);
    // QMessageBox::information(ui->pushButton, "Combination", message);

    for (int i = 0;i < Steps; i++) {
        lLambda=lLambda_min + i*lStepValue;
        //QMessageBox::information(ui->pushButton, "Lambda", QString::number(lLambda));
        Distance=sqrt((lLambda * Farfield) / 2.0);
        //QMessageBox::information(ui->pushButton, "Farfield", QString::number(Farfield));
        Array[0][i]=std::to_string(Farfield);
        Array[1][i]=std::to_string(lLambda);
        Array[2][i]=std::to_string(Distance);
    }
}


// fix L hold R calc D
void LRD (Ui::MainWindow *ui, int lSteps, float lFarfield, int LPresentage)
{

    float lFarfield_min=lFarfield-(float)LPresentage/100*lFarfield;
    float lFarfield_max=lFarfield+(float)LPresentage/100*lFarfield;
    float lStepValue=(lFarfield_max-lFarfield_min) / (lSteps-1);

    // // Convert floats to QString
    // QString message = "lFarfield_min: " + QString::number(lFarfield_min) +
    //                   "lFarfield_max: " + QString::number(lFarfield_max);
    // QMessageBox::information(ui->pushButton, "Combination", message);

    for (int i = 0;i < Steps; i++) {
        lFarfield=lFarfield_min + i*lStepValue;
        //QMessageBox::information(ui->pushButton, "lFarfield", QString::number(lFarfield));
       // Lambda = (2 * pow(Distance, 2)) / lFarfield;
        Distance=sqrt((Lambda * lFarfield) / 2.0);

        //QMessageBox::information(ui->pushButton, "Distance", QString::number(Distance));
        Array[0][i]=std::to_string(Lambda);
        Array[1][i]=std::to_string(lFarfield);
        Array[2][i]=std::to_string(Distance);
    }
}
// fix D hold R calc L
void DRL (Ui::MainWindow *ui,/*float lFarfield, float LDistance,*/ int lSteps, float lFarfield, int LPresentage)
{

    float lFarfield_min=lFarfield-(float)LPresentage/100*lFarfield;
    float lFarfield_max=lFarfield+(float)LPresentage/100*lFarfield;
    float lStepValue=(lFarfield_max-lFarfield_min) / (lSteps-1);

    // // Convert floats to QString
    // QString message = "lFarfield_min: " + QString::number(lFarfield_min) +
    //                   "lFarfield_max: " + QString::number(lFarfield_max);
    // QMessageBox::information(ui->pushButton, "Combination", message);

    for (int i = 0;i < Steps; i++) {
        lFarfield=lFarfield_min + i*lStepValue;
        //QMessageBox::information(ui->pushButton, "lFarfield", QString::number(lFarfield));
        Lambda = (2 * pow(Distance, 2)) / lFarfield;
       // QMessageBox::information(ui->pushButton, "Lambda", QString::number(Lambda));
        Array[0][i]=std::to_string(Distance);
        Array[1][i]=std::to_string(lFarfield);
        Array[2][i]=std::to_string(Lambda);
    }
}

// fix D hold L calc R
void DLR (Ui::MainWindow *ui,/*float LFarfield, float LDistance,*/ int lSteps, float lLambda, int LPresentage)
{

    float lLambda_min=lLambda-(float)LPresentage/100*lLambda;
    float lLambda_max=lLambda+(float)LPresentage/100*lLambda;
    float lStepValue=(lLambda_max-lLambda_min) / (lSteps-1);

    // // Convert floats to QString
    // QString message = "lLambda_min: " + QString::number(lLambda_min) +
    //                   "\nlLambda_max: " + QString::number(lLambda_max);
    // QMessageBox::information(ui->pushButton, "Combination", message);

    for (int i = 0;i < Steps; i++) {
        lLambda=lLambda_min + i*lStepValue;
        //QMessageBox::information(ui->pushButton, "Lambda", QString::number(lLambda));
        Farfield = (2 * pow(Distance, 2)) / lLambda;
        //QMessageBox::information(ui->pushButton, "Farfield", QString::number(Farfield));
        Array[0][i]=std::to_string(Distance);
        Array[1][i]=std::to_string(lLambda);
        Array[2][i]=std::to_string(Farfield);
    }
}

// fix L hold D calc R
void LDR (Ui::MainWindow *ui,int lSteps, float lDistance, int LPresentage)
{

    float lDistance_min=lDistance-(float)LPresentage/100*lDistance;
    float lDistance_max=lDistance+(float)LPresentage/100*lDistance;
    float lStepValue=(lDistance_max-lDistance_min) / (lSteps-1);

    // // Convert floats to QString
    // QString message = "lDistance_min: " + QString::number(lDistance_min) +
    //                   "lDistance_max: " + QString::number(lDistance_max);
    // QMessageBox::information(ui->pushButton, "Combination", message);

    for (int i = 0;i < Steps; i++) {
        lDistance=lDistance_min + i*lStepValue;
        //QMessageBox::information(ui->pushButton, "Distance", QString::number(lDistance));
        Farfield = (2 * pow(lDistance, 2)) / Lambda;
        //QMessageBox::information(ui->pushButton, "Farfield", QString::number(Farfield));
        Array[0][i]=std::to_string(lDistance);
        Array[1][i]=std::to_string(Lambda);
        Array[2][i]=std::to_string(Farfield);
    }
}



void popTableWidget (Ui::MainWindow *ui, std::string lArray[4][50]){

    QStringList headers;

    // Вземи избраните текстове от двата ComboBox-а
    QString comboBox1Text = ui->comboBox_Fix->currentText();
    QString comboBox2Text = ui->comboBox_Hold->currentText();

    // Възможни стойности
    QString option1 = "Wavelength (λ)";
    QString option2 = "Border (R)";
    QString option3 = "Antenna Size (D)";

    // Провери коя стойност не е избрана
    QString unusedOption;
    if (comboBox1Text != option1 && comboBox2Text != option1) {
        unusedOption = option1;
    } else if (comboBox1Text != option2 && comboBox2Text != option2) {
        unusedOption = option2;
    } else if (comboBox1Text != option3 && comboBox2Text != option3) {
        unusedOption = option3;
    }

    //Set headers:
    headers << ui->comboBox_Fix->currentText() << ui->comboBox_Hold->currentText() << unusedOption;


    ui->tableWidget->setVerticalHeaderLabels(headers);
    // Set the row and column count for the table widget
    ui->tableWidget->setRowCount(3);      // 4 rows
    ui->tableWidget->setColumnCount(50); // 50 columns


    // Populate the table widget
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 50; ++col) {
            // Create a new QTableWidgetItem with the array value
            QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(Array[row][col]));

            // Insert the item into the table widget at the correct position
            ui->tableWidget->setItem(row, col, item);
        }
    }
    //Autosize column widths
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_actionAbout_triggered()
{
    About about;
    about.exec();  // or helpDialog.show();

}


void MainWindow::on_actionHelp_triggered()
{
    HelpDialog helpDialog;
    helpDialog.exec();  // or helpDialog.show();
}


void MainWindow::on_actionClose_triggered()
{
    this->close();
}

