#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent): QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    m_file = "";
    m_filePath = QDir::homePath();
}

void Dialog::save()
{
    QFile imageFile(m_file);
    if(!imageFile.exists()){
        QMessageBox::critical(this, "Message", "Image does not exist!");
        return;
    }
    if(!imageFile.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, "Error", imageFile.errorString());
        return;
    }

    QImage image(m_file);

    if(image.save(m_filePath + "/Desktop/" + ui->nameEdit->text()))
    {
        QMessageBox::information(this, "Message", "Image saved successfully");
    }else{
        QMessageBox::critical(this, "Message", "Image cound not be saved!");
    }
    init();
    imageFile.close();
}

void Dialog::on_clearButton_clicked()
{
    m_file = "";
    ui->nameEdit->setText(m_file);
}

void Dialog::on_saveButton_clicked()
{
    m_file = ":/resources/images/" + ui->nameEdit->text();
    save();
}

void Dialog::on_buttonBox_accepted()
{
    m_file = QFileDialog::getOpenFileName(this, tr("Save Image File"),
                                                   QString(),
                                                   tr("Images (*.png)"));
    if(m_file.isEmpty())
        return;
    save();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}



