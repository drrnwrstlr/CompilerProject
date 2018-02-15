#include "Lexer.h"

#define T_SEMICOLON 59 /';'
#define T_LEFTPAREN 40 /'('
#define T_RIGHTPAREN 41 /')'
#define T_LEFTBRACK 91 /'['
#define T_RIGHTBRAK 93 /']'
#define T_ASSIGN 61 /'='
#define T_ADD 43 /'+'
#define T_SUB 45 /'-'
#define T_DIVIDE 47 /'/'
#define T_MULTIPLY 42 /'*'
#define T_GT 62 /'>'
#define T_LT 60 /'<'
#define T_PERCENT 37 /'%'
#define T_LEFTCURLBRACKET 123 /'{'
#define T_RIGHTCURLBRACKET 125 /'}'
#define T_POWER 94 /'^'
#define T_AND 38 /'&'
#define T_OR 124 /'|'
#define T_APO 39 /'''
#define T_QUOTE 34 /'"'
#define T_PERIOD 46 /'.'

#define T_BEGIN 300
#define T_ENDPROGRAM 301
#define T_GLOBAL 302
#define T_INTEGER 303
#define T_FLOAT 304
#define T_STRING 305
#define T_BOOL 306
#define T_CHAR 307
#define T_IF 308
#define T_THEN 309
#define T_ELSE 310
#define T_ENDIF 311
#define T_FOR 312
#define T_ENDFOR 313
#define T_RETURN 314
#define T_NOT 315
#define T_IDENTIFIER 316


#DEFINE T_UNKNOWN 317

struct token_t {
 int type;
 union{
    char stringValue[256];
    int intValue;
    double doubleValue;
 } val;
}

int main(int argc, char*argv[]){
    struct token_t token;

    InitScanner();
        while(ScanOneToken(stdin, &token) != T_ENDPROGRAM)
    return 0;
}

static void InitSCanner(){
    create_reserved_table();
    insert_reserved("WHILE", T_WHILE)
    insert_reserved("IF", T_IF)
    insert_reserved("THEN", T_THEN)
    insert_reserved("ELSE", T_ELSE)
    insert_reserved("ENDIF", T_ENDIF)
    insert_reserved("FOR", T_FOR)
    insert_reserved("ENDFOR", T_ENDFOR)
    insert_reserved("RETURN", T_RETURN)
    insert_reserved("NOT", T_NOT)
}

static int ScanOneToken(FILE *fp, struct token_t *token){
    int i, ch, nextch;

    ch = getc(fp); // read next character
    while (isspace(ch)) // if necessary, keep reading till non-space char
        ch = getc(fp); // discard white spaces

    switch(ch){
        case '/':
        nextch = getc(fp);
        if(nextch == '/' || nextch == '*')
        ; //skip comment
        else
            ungetc(nextch, fp);

        case ';': case '(': case ')': case '[': case ']': case '=': case '+': case '-': case '*': case '>': case '<': case '%': case '{': case '}': case '^': case '&': case '|': case '.':
            token->type = ch;
            return ch;

        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
            token->val.stringValue[0] = ch;
            for (i=1; isupper(ch = getc(fp)); i++)
                token->val.stringValue[i] = ch;
            ungetc(ch, fp);
            token->val.stringValue[i] = '\0';
            token->type = lookup_reserved(token->val.stringValue);
            return token->type;

        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            token->type = T_IDENTIFIER;
            token->val.stringValue[0] = ch;
            for (i = 1; islower(ch = getc(ft)); i++)
                token->val.stringValue[i] = ch;
            ungetc(ch, fp);
            token->val.stringValue[i] = '\0';
            if (lookup_symtab(token->val.stringValue) == NULL)
                add_symtab(token->val.stringValue);
            return T_IDENTIFIER

        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            token->type = T_INTEGER;
            token->val.intValue = ch - '0';
            while (isdigit(ch = getc(fp)))
                token->val.intValue = token->val.intValue * 10 + ch - '0';
            ungetc(ch, fp);
            return T_INTEGER;

        case EOF:
            return T_ENDPROGRAM

        default:
            token->val.intValue = ch;
            token->type = T_UNKNOWN
            return T_UNKNOWN



    }

}


Lexer::Lexer()
{

}

Lexer::~Lexer()
{
    //dtor
}
