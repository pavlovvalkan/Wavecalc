#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_horizontalSlider_Frq_sliderReleased();

    void on_lineEdit_Freq_returnPressed();

    void on_lineEdit_Lambda_returnPressed();

    void on_horizontalSlider_Farfield_sliderReleased();

    void on_horizontalSlider_Frq_valueChanged(int value);

    void on_horizontalSlider_Farfield_valueChanged(int value);

    void on_lineEdit_Farfield_returnPressed();

    void on_horizontalSlider_3_sliderReleased();

    void on_horizontalSlider_Distance_sliderReleased();

    void on_horizontalSlider_Distnce_sliderReleased();

    void on_lineEdit_Distance_returnPressed();

    void on_lineEdit_SpeedOfSound_returnPressed();

    void on_comboBox_Fix_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_actionAbout_triggered();

    void on_actionHelp_triggered();

    void on_actionClose_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
