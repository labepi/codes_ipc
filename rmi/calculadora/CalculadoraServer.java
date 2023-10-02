// this is the server, wich will register the service

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.Naming;

public class CalculadoraServer 
{

    public static void main(String[] args) 
    {
        try 
        {
            String name = "Calculadora";
            Calculadora calc = new Calculadora();

            Registry registry = LocateRegistry.createRegistry(1099);

            Naming.rebind(name, calc);

            System.out.println("CalculadoraServer bound");
        } 
        catch (Exception e) 
        {
            System.err.println("CalculadoraServer exception:");
            e.printStackTrace();
        }
    }
}
