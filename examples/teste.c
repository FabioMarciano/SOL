#include "SOL/SOL.h"

int main() {

	SOL_Init();

	NODE *teste = NULL;

	teste = SOL.Node.New("teste_1", "Teste 1");
	teste->previous = NULL;
	teste->childNodes = SOL.Node.New("filho_1", "Valor filho de teste 1");
	teste->childNodes->parentNode = teste;

	teste->childNodes->next = SOL.Node.New("filho_2", "Valor filho de teste 2");
	teste->childNodes->next->parentNode = teste;
	teste->childNodes->next->previous = teste->childNodes;
	
	teste->next = SOL.Node.New("teste_2", "Valor teste 2");
	teste->next->previous = teste;

	teste->next->next = SOL.Node.New("teste_3", "Valor teste 3");
	teste->next->next->previous = teste->next;

	printf("Tamanho: %i\n", SOL.Node.Length(teste));
	printf("Posicao: %s\n", teste->value);

	SOL.Node.Jump(&teste, 1);
	printf("Posicao pós Jump(1): %s\n", teste->value);

	SOL.Node.Rewind(&teste);
	printf("Posicao pós Rewind(): %s\n", teste->value);

	SOL.Node.Walk(&teste, 1);
	printf("Posicao pós Walk(1): %s\n", teste->value);

	SOL.Node.Jump(&teste, 0);
	printf("Posicao pós Jump(0): %s\n", teste->value);

	SOL.Node.Walk(&teste, 1);
	printf("Posicao pós Walk(1): %s\n", teste->value);

	SOL.Node.Walk(&teste, 4);
	printf("Posicao pós Walk(4): %s\n", teste->value);

	SOL.Node.Rewind(&teste);

	printf("%s\n", SOL_LOWER_HEXSET);

	/*NODE *env = ENV;

	while(env != NULL) {
		printf("%s: %s\n", env->name, env->value);
		if(env->next != NULL) {
			env = env->next;
		} else {
			break;
		}
	}*/

	printf("------------------------------------------\n\n");
	printf("Environment:\n\n");

	SOL.Node.Dump(ENV);

	printf("------------------------------------------\n\n");

	SOL.Node.Dump(teste);

	printf("------------------------------------------\n\n");

	NODE *tmp = teste->next;

	SOL.Node.Drop(&tmp);

	SOL.Node.Dump(teste);

	printf("+++++++++++++++++++++++++++++++++++++\n\n");


	NODE *agora = SOL.Node.New("primeiro", "valor do primeiro");
	SOL.Node.Dump(agora);
	printf("------------------------------------------\n\n");

	SOL.Node.Push(&agora, "segundo", "valor do segundo");
	SOL.Node.Push(&agora, "terceiro", "valor do terceiro");
	SOL.Node.Push(&agora, "quarto", "valor do quarto");
	SOL.Node.Push(&agora, "quinto", "valor do quinto");

	SOL.Node.Append(&agora, SOL.Node.New("Ultimo", "valor do last"));
	SOL.Node.Prepend(&agora, SOL.Node.New("PRIMEIRO", "Prependando o novo primeiro"));
	SOL.Node.Prepend(&agora, SOL.Node.New("SEGUNDO", "Prependando o novo primeiro"));
	SOL.Node.Prepend(&agora, SOL.Node.New("TERCEIRO", "Prependando o novo primeiro"));

	SOL.Node.Rewind(&agora);

	SOL.Node.Dump(agora);

	printf("------------------------------------------\n\n%i itens\n\n", SOL.Node.Length(agora));

	SOL.Node.Set.Value(&agora, "Alterado primeiro");
	SOL.Node.Jump(&agora, 3);
	SOL.Node.Set.Value(&agora, "Alterado Quarto item");
	SOL.Node.Dump(agora);

	printf("%s\n", SOL.String.ToLowerCase("TESTETETETETETETE"));
	printf("Compara: %i\n", SOL.String.Compare("lore", "Lore"));
	printf("Compara: %i\n", SOL.String.Compare("lore", "lore"));

	printf("SAIDA: %s\n", SOL.String.Replace("cia", "tia", "Fábio Marciano"));

	printf("MD5: %s\n", SOL.Crypt.MD5("Fábio Marciano"));
	printf("SHA1: %s\n", SOL.Crypt.SHA1("Fábio Marciano"));
	printf("Url encode: %s\n", SOL.Crypt.Encode.Url("Fábio Marciano"));
	printf("Url decode: %s\n", SOL.Crypt.Decode.Url("F%c3%a1bio+Marciano"));
	printf("B64 encode: %s\n", SOL.Crypt.Encode.Base64("fabio marciano"));
	printf("B64 decode: %s\n", SOL.Crypt.Decode.Base64("ZmFiaW8gbWFyY2lhbm8="));
	printf("0x20 vale: %i\n", SOL.Crypt.Decode.Hex("20"));
	printf("0xAF vale: %i\n", SOL.Crypt.Decode.Hex("AF"));
	printf("175 vale: 0x%s\n", SOL.Crypt.Encode.Hex(175));
	printf("32 vale: 0x%s\n", SOL.Crypt.Encode.Hex(32));

	DB db, db2;
	SOL.DB.New(&db, SOL_DB_TYPE_MYSQL);
	SOL.DB.New(&db2, SOL_DB_TYPE_POSTGRES);

	printf("Database type: %i\n", db.Type);
	printf("Database Host: %s\n", db.Host);
	printf("Database Name (antes): %s\n", db.Name);
	SOL.DB.Set.Name(&db, "mysql");
	printf("Database Name (depois): %s\n", db.Name);
	printf("Database User: %s\n", db.User);
	printf("Database Password: %s\n", db.Password);
	printf("Database Port: %i\n", db.Port);
	printf("Database type: %i\n", db2.Type);

	printf("Status DB: %i\n", SOL.DB.Status(&db));
	SOL.DB.Connect(&db);
	printf("Status DB: %i\n", SOL.DB.Status(&db));

	SOL.DB.Set.Host(&db2, "localhost");
	SOL.DB.Set.User(&db2, "root");
	SOL.DB.Set.Password(&db2, "admin");
	SOL.DB.Set.Name(&db2, "postgres");
	printf("Status DB2: %i\n", SOL.DB.Status(&db2) );
	SOL.DB.Connect(&db2);
	printf("Status DB2: %i\n", SOL.DB.Status(&db2));

	SOL_Quit();

	return 0;
}


