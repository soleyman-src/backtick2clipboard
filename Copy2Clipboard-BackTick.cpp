#include<string.h>
#include<Windows.h>
#include<iostream>
using namespace std;

//funzione copytoclipboard
void copytoclipboard(const std::string& tocopy)
{
    OpenClipboard(NULL);
    EmptyClipboard();
    HGLOBAL HG = GlobalAlloc(GMEM_MOVEABLE, tocopy.size());
    if (!HG) 
    {
        CloseClipboard();
    }
    memcpy(GlobalLock(HG), tocopy.c_str(), tocopy.size());
    GlobalUnlock(HG);
    SetClipboardData(CF_TEXT, HG);
    CloseClipboard();//nofunc
    GlobalFree(HG);
}

int main()
{
	ShowWindow( GetConsoleWindow(), SW_HIDE ); //comando che nasconde la finestra
    copytoclipboard("`a");	//comando che copia il carattere backtick nella clipboard - NB: aggiungere una lettera casuale alla fine perchè il programma non copia l'ultima lettera
}
