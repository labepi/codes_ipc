import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.Naming;
//import java.rmi.*;

public class CalculadoraClient
{
    public static void main(String[] args)
    {
        if (args.length < 2)
        {
            System.out.println("Usage: java CalculadoraClient num1 num2");
            return;
        }

        int num1 = Integer.parseInt(args[0]);
        int num2 = Integer.parseInt(args[1]);

        try
        {
            CalculadoraInterface calc = (CalculadoraInterface)
                Naming.lookup("rmi://127.0.0.1:1099/Calculadora");

            System.out.println("Soma: " + calc.somar(num1, num2));
            System.out.println("Subtração: " + calc.subtrair(num1, num2));
        }
        catch(Exception e)
        {
            System.out.println("CalculadoraClient exception: " + e);
        }
    }
}

