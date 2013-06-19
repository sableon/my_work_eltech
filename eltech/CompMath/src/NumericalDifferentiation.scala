import math._
import scala.math.Numeric.DoubleAsIfIntegral

/**
 * Created with IntelliJ IDEA.
 * User: SabLeOn
 * Date: 18.05.13
 * Time: 11:13
 * To change this template use File | Settings | File Templates.
 */
object NumericalDifferentiation {

  def f(x:Double):Double = (exp(x + 5) * cos(7 * pow(x, 4)) * (x - 2)) / (1 + pow(atan(3 + x), 2))
  def left_f_deriv(x:Double, h:Double):Double = (f(x) - f(x - h)) / h
  def right_f_deriv(x:Double, h:Double):Double = (f(x + h) - f(x)) / h
  def mid_f_deriv(x:Double, h:Double):Double = (f(x + h) - f(x - h)) / (2 * h)
  def f_deriv(x:Double):Double = {
    val COS = cos(7 * pow(x, 4))
    val DEN = 1 + pow(atan(x + 3), 2)

    val B = COS * (x - 2)
    val dB = COS - 28 * pow(x, 3) * (x - 2) * sin(7 * pow(x, 4))
    val C = DEN
    val dC = 2 * atan(3 + x) / (1 + pow(x + 3, 2))
    val A = (x - 2) * COS / DEN
    val dA = (dB * C - B * dC)/pow(C, 2)

    exp(x+5) * (A + dA)
  }

  val valueX:List[Double] = List.range[Double](0, 2.1, 0.1)(new DoubleAsIfIntegral {
    def compare(x: Double, y: Double): Int = {
      if(x < y) return -1
      else if (x > y) return 1
      else return 0
    }
  })
  val h0 = 0.01
  val MINIMUM_DELTA:Double = 0.0001

  def isEnd(a:Array[Double], b:Array[Double]):Boolean = {
    var result = true
    (a, b).zipped foreach { (j, k) =>
      result = result && (math.abs(j - k) <= MINIMUM_DELTA*10)
    }
    return result
  }

  def calculateArray(delta:Double, func: (Double, Double) => Double):Array[Double] = {
    val result:Array[Double] = new Array[Double](valueX.length)
    (valueX, (0 to valueX.length - 1)).zipped foreach {(x, j) =>
      result.update(j, func(x, delta))
    }
    return result
  }

  def iterate(deriv: (Double, Double) => Double):(Array[Double], Double) = {
    var h = h0
    var previousStep = calculateArray(h, deriv)
    var currentStep = previousStep
    var over = false

    do {      
      //write previous step into buffers
      previousStep = currentStep
      //calculate next step
      h = h/2.0
      currentStep = calculateArray(h, deriv)
      if(isEnd(currentStep, previousStep)) over = true
    } while(!over)

    return (currentStep, h)
  }

  def printArray(output: (Array[Double], Double)) = {
    Console.println("Конечный шаг h = %e".format(output._2))
    (valueX, output._1).zipped foreach { (x, fx) => {
        Console.print("f(%.1f) = %.4f".format(x, fx))
        if (math.abs(fx - f_deriv(x)) > MINIMUM_DELTA) Console.println(" *")
        else Console.println()
      }
    }
  }

  def main(args: Array[String]):Unit = {
    println("Результаты вычислений по формулам левой производной: ")
    printArray(iterate(left_f_deriv))
    println("Результаты вычислений по формулам правой производной: ")
    printArray(iterate(right_f_deriv))
    println("Результаты вычислений по формулам центральной производной: ")
    printArray(iterate(mid_f_deriv))
    println("Точное значение производной:")
    valueX foreach {x => println("f(%.1f) = %.4f".format(x, f_deriv(x)))}
  }
}
