#include "helpdialog.h"
#include "ui_helpdialog.h"
#include <QFile>       // For QFile
#include <QTextStream> // For QTextStream
#include <QIODevice>   // For QIODevice
#include <QDesktopServices>  // For opening links in the default browser
#include <QUrl>              // To handle URLs



HelpDialog::HelpDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    // Load HTML file from the project directory or resources
    QFile file(":/help.html");  // Assuming the file is added to resources, see resource steps below
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString htmlContent = stream.readAll();
        ui->textBrowserHelp->setHtml(htmlContent);  // Load the content into QTextBrowser
        file.close();
    }
    else
    {
        ui->textBrowserHelp->setText("Failed to load help content.");
    }


    // Prevent QTextBrowser from handling links internally
    ui->textBrowserHelp->setOpenLinks(false);

    // Connect anchorClicked to a custom slot to open external links
    connect(ui->textBrowserHelp, &QTextBrowser::anchorClicked, this, &HelpDialog::onLinkClicked);

}

HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::onLinkClicked(const QUrl &url)
{
    // Open the link in the default web browser
    QDesktopServices::openUrl(url);
}
