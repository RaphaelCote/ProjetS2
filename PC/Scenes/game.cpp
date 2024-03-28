#include <cmath>
#include <stdio.h>
#include <math.h>

#include "game.h"
#include "../raftWars.h"
#include "../Game/rocket.h"
#include "../Game/canonball.h"
#include "../Game/grenade.h"
#include "../Game/enemyCharacter.h"
#include "../Game/projectile.h"

std::chrono::_V2::system_clock::time_point startAnimation;
std::chrono::duration<double, std::milli> currentclockAnimation;
std::chrono::duration<double, std::milli> timerAnimation;

/*Méthodes*/
/*Constructeur (État Initial)*/
Game::Game()
{
    currentLevelIndex = 0;
    turn = 0;
    isPlayerTurn = true;
    isPause = false;
    isNewLevel = true;
    projectileType = 0;
}

int Game::GetLevelIndex()
{
    return currentLevelIndex;
}

void Game::SetLevelIndex(int level)
{
    currentLevelIndex = level;
}

void OnGameMainActionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->PlayerShoot();
}

void OnGameNextSelectionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->ChangeProjectileType(1);
}

void OnGamePreviousSelectionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->ChangeProjectileType(-1);
}

void OnGameJoystickCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    float a = ep.parameter1;
    float strength = sqrt(a * a);
    game->ChangeProjectileStrength(strength);
}

void OnGameAngleCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->ChangeProjectileAngle(ep.parameter1);
}

void OnGameMenuCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->PauseGame();
}

void Game::ChangeProjectileType(int typeDif)
{
    if (typeDif > 0)
    {
        for (int i = projectileType + 1; i <= 2; i++)
        {
            if (CheckAvailableProjectile(i))
            {
                projectileType = i;
                break;
            }
        }
    }
    else if (typeDif < 0)
    {
        for (int i = projectileType - 1; i >= 0; i--)
        {
            if (CheckAvailableProjectile(i))
            {
                projectileType = i;
                break;
            }
        }
    }

    float angle = projectile->getAngleDegre();
    float puissance = projectile->getPuissance();

    if (projectileType == 0)
    {
        projectile = new Canonball(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());
    }
    else if (projectileType == 1)
    {
        projectile = new Rocket(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());
    }
    else if (projectileType == 2)
    {
        projectile = new Grenade(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());
    }

    projectile->setAngleDegre(angle);
    projectile->setPuissance(puissance);
}

void Game::ChangeProjectileStrength(float strength)
{
    projectile->setPuissance(strength);
}

void Game::ChangeProjectileAngle(float angle)
{
    projectile->setAngleDegre(angle);
}

void Game::OnEnable()
{
    eventManager->on("MainAction", OnGameMainActionCall);
    eventManager->on("NextSelection", OnGameNextSelectionCall);
    eventManager->on("PreviousSelection", OnGamePreviousSelectionCall);
    eventManager->on("Joystick", OnGameJoystickCall);
    eventManager->on("Angle", OnGameAngleCall);
    eventManager->on("Menu", OnGameMenuCall);
}

void Game::OnDisable()
{
    eventManager->off("MainAction", OnGameMainActionCall);
    eventManager->off("NextSelection", OnGameNextSelectionCall);
    eventManager->off("PreviousSelection", OnGamePreviousSelectionCall);
    eventManager->off("Joystick", OnGameJoystickCall);
    eventManager->off("Angle", OnGameAngleCall);
    eventManager->off("Menu", OnGameMenuCall);
}

void Game::Update()
{
    OnEnable();

    if (isNewLevel)
    {
        // Load level from start
        turn == 0;
        isPlayerTurn = true;
        projectileType = 0;
        // Load level currentLevelIndex
        activeLevel = gameloader.getLevelFromJson(levelGetter->levels[currentLevelIndex]);

        projectile = new Canonball(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());

        // Ajouter le shield au joueur
        for (int i = 0; i < activeLevel->playerBoats.getSize(); i++)
        {
            for (int j = 0; j < activeLevel->playerBoats[i]->characters.getSize(); j++)
            {
                int newHealthPoints = activeLevel->playerBoats[i]->characters[j]->getHealthPoint() + inventory->getShield();
                activeLevel->playerBoats[i]->characters[j]->setHealthPoint(newHealthPoints);
            }
        }

        activeLevel->MatWater();
        activeLevel->MatNuage();
        activeLevel->MatRaft();
        activeLevel->MatCharacter();
        activeLevel->MatEnemy();
    }

    isNewLevel = false;
    PlayTurn();
}

void Game::PlayTurn()
{
    turn++;
    if (isPlayerTurn)
    {
        if (doOnce)
        {
            Sleep(10);
            ShowGameInfo();
            doOnce = false;
        }
        UpdateWeaponInfo();
    }
    else
    {
        EnemyCharacter *ec = (EnemyCharacter *)activeLevel->enemyBoats[0]->characters[0];
        Projectile *enemyProjectile = ec->createEnemyProjectile();

        activeLevel->MatBalle(enemyProjectile);

        enemyProjectile->checkIfCharacterHit(*(activeLevel->playerBoats[0]->characters[0]));

        AnimationProjectile(enemyProjectile);

        isPlayerTurn = true;
        doOnce = true;
    }

    if (CheckEndCondition())
    {
        EndGame();
    }
}

void Game::PlayerShoot()
{
    if (!isPlayerTurn)
    {
        return;
    }

    if (projectileType == 0)
    {
        activeLevel->MatBalle(projectile);
    }
    else if (projectileType == 1)
    {
        activeLevel->MatRocket(projectile);
    }
    else if (projectileType == 2)
    {
        activeLevel->MatGrenade(projectile);
    }

    projectile->checkIfCharacterHit(*(activeLevel->enemyBoats[0]->characters[0]));

    AnimationProjectile(projectile);

    // Remove special projectiles if fired, and if no more special projectiles are available, change to previous type
    if (projectileType == 1)
    {
        inventory->removeRockets();
        if (inventory->getRockets() == 0)
        {
            ChangeProjectileType(-1);
        }
    }
    else if (projectileType == 2)
    {
        inventory->removeGrenade();
        if (inventory->getGrenade() == 0)
        {
            ChangeProjectileType(-1);
        }
    }

    isPlayerTurn = false;
}

void Game::PauseGame()
{
    OnDisable();
    activeScene = 4;
}

void Game::EndGame()
{
    PayPlayer();
    OnDisable();
    StopGame();
    activeScene = 3;
}

void Game::PayPlayer()
{
    bool isAllPlayerDead = true;

    for (int i = 0; i < activeLevel->playerBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->playerBoats[i]->characters.getSize(); j++)
        {

            if (activeLevel->playerBoats[i]->characters[j]->getHealthPoint() > 0)
            {
                isAllPlayerDead = false;
            }
        }
    }

    // Check if all players are dead
    if (isAllPlayerDead)
    {
        // Player dead
        inventory->addGold(200);
        // cout << "-------------------------------------------------------------------" << endl;
        // cout << "Vous avec recu 200$" << endl;
        // cout << "-------------------------------------------------------------------" << endl;
    }
    else
    {
        // Enemy dead
        inventory->addGold(1200);
        // cout << "-------------------------------------------------------------------" << endl;
        // cout << "Vous avec recu 1200$" << endl;
        // cout << "-------------------------------------------------------------------" << endl;
    }
}

void Game::StoreShield()
{
    int totalHealth = 0;
    int nbPlayer = 0;

    for (int i = 0; i < activeLevel->playerBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->playerBoats[i]->characters.getSize(); j++)
        {
            totalHealth += activeLevel->playerBoats[i]->characters[j]->getHealthPoint();
            nbPlayer++;
        }
    }

    int averageHealth = totalHealth / nbPlayer;

    if (averageHealth > 100)
    {
        inventory->setShield(averageHealth - 100);
    }
}

void Game::StopGame()
{
    StoreShield();

    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
    cons->SupprimerObjet("s5");
    cons->SupprimerObjet("s6");

    activeLevel->Delete();
}

bool Game::CheckEndCondition()
{
    for (int i = 0; i < activeLevel->playerBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->playerBoats[i]->characters.getSize(); j++)
        {
            bool isAllPlayerDead = true;
            if (activeLevel->playerBoats[i]->characters[j]->getHealthPoint() > 0)
            {
                isAllPlayerDead = false;
            }

            if (isAllPlayerDead)
            {
                return true;
            }
        }
    }

    for (int i = 0; i < activeLevel->enemyBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->enemyBoats[i]->characters.getSize(); j++)
        {
            bool isAllEnemyDead = true;
            if (activeLevel->enemyBoats[i]->characters[j]->getHealthPoint() > 0)
            {
                isAllEnemyDead = false;
            }

            if (isAllEnemyDead)
            {
                return true;
            }
        }
    }

    return false;
}

bool Game::CheckAvailableProjectile(int type)
{
    if (type == 0)
    {
        return true;
    }
    else if (type == 1)
    {
        if (inventory->getRockets() > 0)
        {
            return true;
        }
    }
    else if (type == 2)
    {
        if (inventory->getGrenade() > 0)
        {
            return true;
        }
    }

    return false;
}

void Game::ShowGameInfo()
{

    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
    cons->SupprimerObjet("s5");

    Sleep(10);

    string s0 = "------- Niveau " + to_string(currentLevelIndex) + " ------- ";
    string s1 = "Vie du joueur : " + to_string(activeLevel->playerBoats[0]->characters[0]->getHealthPoint()) + " ";
    string s2 = "Vie des enemies : ";
    string s3 = "";
    for (int i = 0; i < activeLevel->enemyBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->enemyBoats[i]->characters.getSize(); j++)
        {
            if (i != 0 && j != 0)
            {
                s3 += "| ";
            }

            s3 += "Enemy " + to_string(i) + to_string(j) + " : " + to_string(activeLevel->enemyBoats[i]->characters[j]->getHealthPoint()) + " ";
        }
    }
    string s4 = "Inventaire : " + to_string(inventory->getRockets()) + " rockets, " + to_string(inventory->getGrenade()) + " grenades ";
    string s5 = "Projectile selectionne : ";

    if (projectileType == 0)
    {
        s5 += "Balle ";
    }
    else if (projectileType == 1)
    {
        s5 += "Rocket ";
    }
    else if (projectileType == 2)
    {
        s5 += "Grenade ";
    }

    // cout << "\n"
    //         "-------FORMULE DE LA PARABOLE-------"
    //      << endl;
    // cout << "y = g"
    //      << "x^2 / (2(" << projectile->getPuissance() << "Vmax)^2 . cos^2(" << projectile->getAngleDegre() * PI / 180 << ") ) + xtan(" << projectile->getAngleDegre() * PI / 180 << ")"
    //      << "\n"
    //      << endl;

    // activeLevel->ShowLevelInfo(cout);

    int y0 = ((cons->MaxRows) * 10) - 30;
    int y1 = ((cons->MaxRows) * 10) - 40;
    int y2 = ((cons->MaxRows) * 10) - 50;
    int y3 = ((cons->MaxRows) * 10) - 60;
    int y4 = ((cons->MaxRows) * 10) - 80;
    int y5 = ((cons->MaxRows) * 10) - 90;
    int x = 20;

    cons->AfficherTexte(std::cout, s0, x, y0, "s0");
    cons->AfficherTexte(std::cout, s1, x, y1, "s1");
    cons->AfficherTexte(std::cout, s2, x, y2, "s2");
    cons->AfficherTexte(std::cout, s3, x, y3, "s3");
    cons->AfficherTexte(std::cout, s4, x, y4, "s4");
    cons->AfficherTexte(std::cout, s5, x, y5, "s5");
}

void Game::UpdateWeaponInfo()
{
    cons->SupprimerObjet("s6");

    Sleep(10);

    string s6 = "Votre angle : " + to_string(projectile->getAngleDegre()) + " | Votre puissance : " + to_string(projectile->getPuissance()) + " ";

    int y6 = ((cons->MaxRows) * 10) - 100;
    int x = 20;
    cons->AfficherTexte(std::cout, s6, x, y6, "s6");
}

void Game::AnimationProjectile(Projectile *projectile)
{
    bool animation = true;
    Coordonnee currentPosition = projectile->bulletStartPosition;
    Coordonnee endPosition = projectile->bulletEndPosition;
    float time = 0.0f;
    bool coterAnimationGauche;

    // Pour debug
    // endPosition.x = 1000;
    ////////////////////////////////////////////////////////////////////////////////

    if (currentPosition.x - endPosition.x <= 0)
        coterAnimationGauche = true;
    else
        coterAnimationGauche = false;

    startAnimation = std::chrono::high_resolution_clock::now();

    int lastPositionY = currentPosition.y;

    while (animation)
    {
        const auto now = std::chrono::high_resolution_clock::now();
        currentclockAnimation = now - startAnimation;

        if ((currentclockAnimation.count() - timerAnimation.count()) > 10)
        {
            time += 0.01;

            lastPositionY = currentPosition.y;

            currentPosition.y = positionYTemps(time, projectile);

            if (currentPosition.y >= lastPositionY)
            {
                currentPosition.x = findX(currentPosition.y, projectile, 1);
            }
            else
            {
                currentPosition.x = findX(currentPosition.y, projectile, 2);
            }

            // currentPosition.y = projectile->findBulletPositionYTime(time);
            // currentPosition.x = projectile->findBulletPositionX(currentPosition.y);
            // currentPosition.x++;
            // currentPosition.y = projectile->findBulletPositionY(currentPosition.x);
            projectile->bulletCurrentPosition = currentPosition;
            cons->Mincolums = (currentPosition.x - (cons->MaxColumns * 10 - cons->Mincolums * 10) / 2) / 10; // je fais * 10 pcq c l'affichage console

            cons->SupprimerObjet("text");
            cons->SupprimerObjet("text2");
            cons->SupprimerObjet("text3");
            cons->SupprimerObjet("text4");
            cons->SupprimerObjet("text5");

            cons->AfficherTexte(std::cout, "BulletPositionX: " + to_string(projectile->bulletCurrentPosition.x), cons->Mincolums * 10 + (cons->MaxColumns * 10 - cons->Mincolums * 10) / 2, 160, "text");
            cons->AfficherTexte(std::cout, "BulletEndPositionX: " + to_string(projectile->bulletEndPosition.x), cons->Mincolums * 10 + (cons->MaxColumns * 10 - cons->Mincolums * 10) / 2, 150, "text2");
            cons->AfficherTexte(std::cout, "BulletEndPositionY: " + to_string(projectile->bulletEndPosition.y), cons->Mincolums * 10 + (cons->MaxColumns * 10 - cons->Mincolums * 10) / 2, 140, "text5");
            cons->AfficherTexte(std::cout, "BulletAngle: " + to_string(projectile->angledeg), cons->Mincolums * 10 + (cons->MaxColumns * 10 - cons->Mincolums * 10) / 2, 130, "text3");
            cons->AfficherTexte(std::cout, "Time: " + to_string(time), cons->Mincolums * 10 + (cons->MaxColumns * 10 - cons->Mincolums * 10) / 2, 120, "text4");

            if (coterAnimationGauche)
            {
                if (currentPosition.x >= endPosition.x || currentPosition.x > (cons->MaxColumns * 10) || currentPosition.y < endPosition.y)
                    animation = false;
            }
            else
            {
                if (currentPosition.x <= endPosition.x || currentPosition.x < 0 || currentPosition.y < endPosition.y)
                    animation = false;
            }

            timerAnimation = currentclockAnimation;
        }

        Sleep(1);
    }

    Sleep(6000);

    cons->SupprimerObjet("projectile");

    cons->Mincolums = 0;
}

float Game::positionYTemps(float time, Projectile *projectile)
{
    float V0 = projectile->getPuissance() * projectile->getProjectileMaxSpeed();
    float rad = projectile->getAngleDegre() * PI / 180;

    float num = pow((g * time + V0 * sin(rad)), 2) - pow((V0 * sin(rad)), 2);
    float denum = 2.0 * g;
    float positionfinaleY = (num / denum + projectile->bulletStartPosition.y);

    return positionfinaleY;
}

float Game::findX(float y, Projectile *projectile, int which_posX)
{
    float V0 = projectile->getPuissance() * projectile->getProjectileMaxSpeed();
    float rad = (projectile->getAngleDegre() * PI) / 180;
    float positionX;

    float deltay = (y - projectile->bulletStartPosition.y);
    // printf("DY = %.1f", deltay);
    float numeratorx1 = -tan(rad) + sqrt(pow(tan(rad), 2) - ((2.0 * g) / (pow(V0, 2) * pow(cos(rad), 2))) * -1.0 * deltay);
    float numeratorx2 = -tan(rad) - sqrt(pow(tan(rad), 2) - ((2.0 * g) / (pow(V0, 2) * pow(cos(rad), 2))) * -1.0 * deltay);
    float denominator = g / (pow(0.5 * 2828.0, 2) * pow(cos(rad), 2));

    float positionX1 = (numeratorx1 / denominator) + projectile->bulletStartPosition.x;
    float positionX2 = (numeratorx2 / denominator) + projectile->bulletStartPosition.x;

    if (projectile->rad >= 0)
    {

        if (which_posX == 1)
        {
            positionX = positionX1;
        }
        else
        {
            positionX = positionX2;
        }
    }
    else
    {
        if (which_posX == 1)
        {
            positionX = positionX2;
        }
        else
        {
            positionX = positionX1;
        }
    }
    // printf("positionX1 = %.1f ", positionX1);
    // printf("positionX2 = %.1f\n", positionX2);
    /*if (positionX2 < positionX1)
    {
        positionX = positionX2;
    }
    else
    {
        positionX = positionX1;
    }*/

    return positionX;
}