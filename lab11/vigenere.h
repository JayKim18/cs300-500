#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <algorithm>

class Vigenere {
private:
    std::string key;

    std::string repeatKey(const std::string& msg) const {
        std::string repeatedKey = key;
        while (repeatedKey.size() < msg.size()) {
            repeatedKey += key;
        }
        return repeatedKey.substr(0, msg.size());
    }

    char shiftChar(char ch, int offset) const {
        return 'A' + (ch - 'A' + offset + 26) % 26;
    }

public:
    Vigenere(std::string key) : key(std::move(key)) {
        std::transform(this->key.begin(), this->key.end(), this->key.begin(), ::toupper);
    }

    ~Vigenere() {}

    std::string encrypt(std::string msg) {
        std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
        std::string repeatedKey = repeatKey(msg);
        std::string encryptedMessage;

        for (size_t i = 0; i < msg.size(); ++i) {
            if (std::isalpha(msg[i])) {
                int shift = repeatedKey[i] - 'A';
                encryptedMessage += shiftChar(msg[i], shift);
            } else {
                encryptedMessage += msg[i]; 
            }
        }
        return encryptedMessage;
    }

    std::string decrypt(std::string msg) {
        std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
        std::string repeatedKey = repeatKey(msg);
        std::string decryptedMessage;

        for (size_t i = 0; i < msg.size(); ++i) {
            if (std::isalpha(msg[i])) {
                int shift = repeatedKey[i] - 'A';
                decryptedMessage += shiftChar(msg[i], -shift);
            } else {
                decryptedMessage += msg[i];
            }
        }
        return decryptedMessage;
    }

    bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage) {
        return encrypt(decryptedMessage) == encryptedMsg;
    }

    void setKey(std::string newKey) {
        key = std::move(newKey);
        std::transform(key.begin(), key.end(), key.begin(), ::toupper);
    }
};

#endif
