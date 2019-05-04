#ifndef GAME_H
#define GAME_H


class Game
{
public:
    Game();
    ~Game();

    void loop();

    void exitGame();
private:
    void initialize();

    void terminate();

private:
    bool mExit;
};

#endif // !GAME_H