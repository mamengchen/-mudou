#include "Lexer.h"

struct ASTNode
{
    std::string value;
    std::vector<ASTNode*> children;
};


class Parser
{
private:
    Lexer& lexer_;
    Token currentToken_;

    ASTNode* parseExpression() {
        // 取出当前，currenttoken 指向下一个
        ASTNode* node = new ASTNode{currentToken_.value};
        currentToken_ = lexer_.nextToken();
        return node;
    }
public:
    explicit Parser(Lexer& lexer) : lexer_(lexer) {
        currentToken_ = lexer_.nextToken();
    };

    ASTNode* parse() {
        return parseExpression();
    }
    ~Parser() {};
};


