#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_fatPatchingLoadFatBtn_clicked()
{
    QString fatPath =  QFileDialog::getOpenFileName(
          Q_NULLPTR,
          "NDS Fat",
          QDir::currentPath(),
          "NDS Fat (*.bin)");

    if( !fatPath.isNull() )
    {
      ui->fatPatchingFatPathEdt->setText(fatPath.toUtf8());
    }
}

void MainWindow::on_fatPatchingPatchFatBtn_clicked()
{
    uint32_t positionDiff = 0;
    uint32_t originalPos = ui->fatPatchingOriginalFatFilesAddrEdt->text().toUInt(nullptr, 16);
    uint32_t newPos = ui->fatPatchingNewFatFilesAddrEdt->text().toUInt(nullptr, 16);

    QString dirPath =  QFileDialog::getSaveFileName(
          Q_NULLPTR,
          "NDS FAT",
          "fat.bin",
          "Binary (*.bin)");

    if(dirPath.isNull())
    {
        return;
    }

    if (originalPos < newPos)
    {
        positionDiff = newPos-originalPos;
    } else {
        positionDiff = originalPos-newPos;
    }

    patchFat(ui->fatPatchingFatPathEdt->text().toStdString(), positionDiff, dirPath.toStdString())
            ? QMessageBox::information(this, tr("NDS Factory"), tr("FAT patching completed!"))
            : QMessageBox::critical(this, tr("NDS Factory"), tr("Error patching FAT!"));

}
