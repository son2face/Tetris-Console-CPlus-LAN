#ifndef UI_H
#define UI_H

class UI
{
    public:
        UI();
        virtual~UI();
        void In();
        void NhapMenu(char[] = "menu.txt");
        void NhapHighscore(char [] = "Data.txt");
        void NhapInstrution(char[] = "instruction.txt");
        void NhapSetting(char[] = "setting.txt");
        void NhapAboutme(char[] = "about.txt");
        COORD getsizeContent(vector<string>& _input);
        COORD getsizeContent();
        void setfullscreen();
        void runMENU();
        void runINSTRUCTION();
        void runABOUT();
        void runHIGHSCORE();
        void MENU();
        void Setting();
        void press();
        void NAME();
        void UPDATE();
    protected:

    private:
        int score_high[10],score;
        string name_high[10];
        string Name;
        ENGINE *GAME;
        vector<string> menu;
        vector<string> setting;
        vector<string> instructition;
        vector<string> aboutme;
        COORD toado;
        char KEY;
        int LV, MODE;
        int ni;
        static char Clour[9];
        static char setCFont[17];
        int cclour;
};
#include "UI.cpp"
#endif
