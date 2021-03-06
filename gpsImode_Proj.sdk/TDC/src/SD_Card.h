/*
 * SD_Card.h
 *
 *  Created on: 2016��11��12��
 *      Author: lin.zheng
 */

#ifndef SRC_SD_CARD_H_
#define SRC_SD_CARD_H_

#include "GPS.h"
#include "ffconf.h"
#include "lidar_sys.h"

#define SD_WR_NUM_EACH_FILE		100


/************************** Variable Definitions *****************************/


u32 Platform;

#ifdef __ICCARM__
#pragma data_alignment = 32
u8 DestinationAddress[10*1024*1024];
u8 SourceAddress[10*1024*1024];
#pragma data_alignment = 4
#else
u8 DestinationAddress[10*1024*1024] __attribute__ ((aligned(32)));
u8 SourceAddress[10*1024*1024] __attribute__ ((aligned(32)));
#endif



void Ffs_CreateFileAndSaveData(Lidar_Data *data,  TCHAR *dirPath);

FRESULT Ffs_Init(TCHAR *Path);

int Ffs_FormatData(unsigned int *ChanalData, Time_Data *timeData, char *formatData);

FRESULT Ffs_WriteDataToFileInCorrectPath(TCHAR *Path, char* dataToBeWrite);

void Ffs_GenerateFullPathName(char* fullPath, char *dirPath, char *fileName);

FRESULT Ffs_WriteDataToFileInCorrectLocation(TCHAR *dirPath, char *dataToBeWrite, int offset, unsigned lineNumber, int newFileFlag);

FRESULT Ffs_CreateNewFile(int index, TCHAR *Path, TCHAR *filePath);

FRESULT Ffs_CloseFile(TCHAR *filePath);
#endif /* SRC_SD_CARD_H_ */
