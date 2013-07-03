/*
 * This file contains instantiation statements to create complex
 * support structures.  The structures will be used in the SCL to
 * validate user requests to instantiate complex entities.
 */

#include "complexSupport.h"

ComplexCollect * gencomplex()
/*
 * This function contains instantiation statments for all the
 * ComplexLists and EntLists in a ComplexCollect.  The instan-
 * stiation statements were generated in order of lower to
 * higher, and last to first to simplify creating some of the
 * links between structures.  Because of this, the code is not
 * very readable, but does the trick.
 */
{
    ComplexCollect * cc;
    ComplexList * cl;
    EntList * node, *child, *next1, *next2, *next3, *next4;

    cc = new ComplexCollect;

    // ComplexList with supertype "shape":
    node = new SimpleList( "square" );
    next4 = node;
    node = new SimpleList( "rectangle" );
    next4->prev = node;
    node->next = next4;
    child = node;
    node = new AndList;
    ( ( MultList * )node )->appendList( child );
    next3 = node;
    node = new SimpleList( "rectangle" );
    next3->prev = node;
    node->next = next3;
    child = node;
    node = new OrList;
    ( ( MultList * )node )->appendList( child );
    next2 = node;
    node = new SimpleList( "triangle" );
    next2->prev = node;
    node->next = next2;
    next2 = node;
    node = new SimpleList( "circle" );
    next2->prev = node;
    node->next = next2;
    child = node;
    node = new OrList;
    ( ( MultList * )node )->appendList( child );
    next1 = node;
    node = new SimpleList( "shape" );
    next1->prev = node;
    node->next = next1;
    child = node;
    node = new AndList;
    ( ( MultList * )node )->appendList( child );
    cl = new ComplexList( ( AndList * )node );
    cl->buildList();
    cl->head->setLevel( 0 );
    cc->insert( cl );

    return cc;
}
