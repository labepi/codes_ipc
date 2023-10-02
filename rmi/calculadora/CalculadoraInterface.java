// this is the interface
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface CalculadoraInterface extends Remote
{
    public int somar(int a, int b) throws RemoteException;
    public int subtrair(int a, int b) throws RemoteException;
}
