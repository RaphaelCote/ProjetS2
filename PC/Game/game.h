#include <iostream>

using namespace std;


class Game
    {
        private: 
        bool Active;
        int actualLevel;
        bool actualTurn; 
        bool Pause;
        /*PERSONNAGE 1 ET PERSONNAGE 2*/
        /*ne pas oublier d'inclure vecteur et le const (si nécessaire)*/
        public:

        Game();
        int activeLevel();
        bool IsPlayerTurn();
        void OnDisable();
        void OnEnable();
        bool StartGame();
        bool PauseGame();
        bool NextLevel();
        bool EndGame();
        void PlayTurn();
        bool CreateLevels();
        bool CheckWinCondition();
        bool CheckLoseCondition();



    };