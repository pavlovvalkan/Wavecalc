#include "about.h"
#include "ui_about.h"
#include <QFile>       // For QFile
#include <QTextStream> // For QTextStream
#include <QIODevice>   // For QIODevice
#include <QDesktopServices>  // For opening links in the default browser
#include <QUrl>              // To handle URLs

About::About(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);

    // Load HTML file from the project directory or resources
    QFile file(":/about.html");  // Assuming the file is added to resources, see resource steps below
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString htmlContent = stream.readAll();
        ui->textBrowserAbout->setHtml(htmlContent);  // Load the content into QTextBrowser
        file.close();
    }
    else
    {
        ui->textBrowserAbout->setText("Failed to load about content.");
    }
    // Prevent QTextBrowser from handling links internally
    ui->textBrowserAbout->setOpenLinks(false);

    // Connect anchorClicked to a custom slot to open external links
    connect(ui->textBrowserAbout, &QTextBrowser::anchorClicked, this, &About::onLinkClicked);
}



About::~About()
{
    delete ui;
}

void About::onLinkClicked(const QUrl &url)
{
    // Open the link in the default web browser
    QDesktopServices::openUrl(url);
}
