#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/objects.h>
#include <openssl/comp.h>

COMP_CTX *COMP_CTX_new(COMP_METHOD *meth)
	{
	COMP_CTX *ret;

	if ((ret=(COMP_CTX *)Malloc(sizeof(COMP_CTX))) == NULL)
		{
		/* ZZZZZZZZZZZZZZZZ */
		return(NULL);
		}
	memset(ret,0,sizeof(COMP_CTX));
	ret->meth=meth;
	if ((ret->meth->init != NULL) && !ret->meth->init(ret))
		{
		Free(ret);
		ret=NULL;
		}
#if 0
	else
		CRYPTO_new_ex_data(rsa_meth,(char *)ret,&ret->ex_data);
#endif
	return(ret);
	}

void COMP_CTX_free(COMP_CTX *ctx)
	{
	/* CRYPTO_free_ex_data(rsa_meth,(char *)ctx,&ctx->ex_data); */

	if(ctx == NULL)
	    return;

	if (ctx->meth->finish != NULL)
		ctx->meth->finish(ctx);

	Free(ctx);
	}

int COMP_compress_block(COMP_CTX *ctx, unsigned char *out, int olen,
	     unsigned char *in, int ilen)
	{
	int ret;
	if (ctx->meth->compress == NULL)
		{
		/* ZZZZZZZZZZZZZZZZZ */
		return(-1);
		}
	ret=ctx->meth->compress(ctx,out,olen,in,ilen);
	if (ret > 0)
		{
		ctx->compress_in+=ilen;
		ctx->compress_out+=ret;
		}
	return(ret);
	}

int COMP_expand_block(COMP_CTX *ctx, unsigned char *out, int olen,
	     unsigned char *in, int ilen)
	{
	int ret;

	if (ctx->meth->expand == NULL)
		{
		/* ZZZZZZZZZZZZZZZZZ */
		return(-1);
		}
	ret=ctx->meth->expand(ctx,out,olen,in,ilen);
	if (ret > 0)
		{
		ctx->expand_in+=ilen;
		ctx->expand_out+=ret;
		}
	return(ret);
	}
