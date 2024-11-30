#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <algorithm>

/**
 * @brief A class to implement the Vigenère cipher for encrypting and decrypting messages.
 * 
 * The Vigenère cipher uses a key to shift letters of a message alphabetically.
 * It can encrypt and decrypt messages and validate encryption using a provided key.
 */
class Vigenere {
private:
    std::string key; ///< The private key used for encryption and decryption.

    /**
     * @brief Repeats the key to match the length of the given message.
     * 
     * @param msg The message whose length the key will match.
     * @return A string with the repeated key of the same length as the message.
     */
    std::string repeatKey(const std::string& msg) const;

    /**
     * @brief Shifts a character alphabetically by a specified offset.
     * 
     * @param ch The character to shift.
     * @param offset The number of positions to shift (can be positive or negative).
     * @return The shifted character.
     */
    char shiftChar(char ch, int offset) const;

public:
    /**
     * @brief Constructs a Vigenere cipher object with the given key.
     * 
     * @param key The key used for encryption and decryption (uppercase letters only).
     */
    Vigenere(std::string key);

    /**
     * @brief Destructor for the Vigenere class.
     */
    ~Vigenere();

    /**
     * @brief Encrypts a given message using the key.
     * 
     * @param msg The message to be encrypted (uppercase letters only).
     * @return The encrypted message.
     */
    std::string encrypt(std::string msg);

    /**
     * @brief Decrypts a given encrypted message using the key.
     * 
     * @param msg The encrypted message to be decrypted (uppercase letters only).
     * @return The decrypted message.
     */
    std::string decrypt(std::string msg);

    /**
     * @brief Checks if an encrypted message matches a given decrypted message after encryption.
     * 
     * @param encryptedMsg The encrypted message.
     * @param decryptedMessage The original decrypted message.
     * @return True if the encrypted message matches the encrypted version of the decrypted message, otherwise false.
     */
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);

    /**
     * @brief Updates the key used for encryption and decryption.
     * 
     * @param key The new key (uppercase letters only).
     */
    void setKey(std::string key);
};

#endif
