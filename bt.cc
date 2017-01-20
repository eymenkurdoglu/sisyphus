void bt::inorderWalk( void )
{

if ( left ) left->inorderWalk();
std::cout << data << endl;
if ( right ) right->inorderWalk();

}
