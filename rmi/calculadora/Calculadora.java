// this is the implementation of the interface
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Calculadora extends UnicastRemoteObject implements CalculadoraInterface
{
    public Calculadora() throws RemoteException
    {
        super();
    }

    public int somar(int a, int b) throws RemoteException
    {
        return (a + b);
    }
    
    public int subtrair(int a, int b) throws RemoteException
    {
        return (a - b);
    }
}
