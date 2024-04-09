#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QTimer>
//include a frank
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <cwchar>
#include <windows.h>
#include <wincon.h>
#include <vector>
//type de media
const int play_Music = 1;
const int play_SoundTrack = 2;
const int stop_Music = 11;
const int stop_SoundTrack = 12;
//type de musique
const int introMusic = 3;
const int gameMusic = 4;
const int victoryMusic = 5;
const int rightRound = 6;//when you win every level
//type de soundtrack
const int canonSoundEffect = 7;
const int explosionSoundEffect = 8;
const int timerBombSoundEffect = 9;
const int warDrumSoundEffect = 10;


class SoundManager :public QObject
{
	Q_OBJECT
	public:
		SoundManager();
		~SoundManager();
		void playMusic();
		void playSoundTrack();
		void stopMusic();// should stop the media (soundEffect or music) that is active
		void stopSoundTrack();
		void gestionnaireMusic();
		int functionDecider;
		int music;
		int soundTrack;
	private:
		QAudioOutput* musicPlayerOutput;
		QMediaPlayer* musicPlayer;

		QAudioOutput* soundTrackPlayerOutput;
		QMediaPlayer* soundTrackPlayer;

	private slots:
		void onMediaStatusChanged(QMediaPlayer::MediaStatus status)
		{
			if (status == QMediaPlayer::EndOfMedia)
			{
				qDebug() << "Media playback finished.";
				//loopMusic(music, volumeIntensity);
			}
		}
	signals:
		void loopMusic(int music, int volumeIntensity);//maybe no parameters are needed

};
#endif