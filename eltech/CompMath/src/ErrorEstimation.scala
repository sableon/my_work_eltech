import java.lang
import scala.math._;
/**
 * Created with IntelliJ IDEA.
 * User: SabLeOn
 * Date: 17.05.13
 * Time: 20:22
 * To change this template use File | Settings | File Templates.
 */

class Number( val value:Double,
              val a_error:Double,
              val r_error:Double) {
  def this(const:Int) = this(const, 0,0)
  def this(v:Double, a:Double) = this(v, a, a / v)

  def +(that:Number) = new Number(value + that.value,
                                  a_error + that.a_error,
                                  (a_error + that.a_error) / (value + that.value)
  )

  def -(that:Number) = new Number(value - that.value,
                                  a_error + that.a_error,
                                  (a_error + r_error) / (value - that.value)
  )

  def *(that:Number) = new Number(value * that.value,
                                  abs(value) * that.a_error + abs(that.value) * a_error + a_error * that.a_error,
                                  r_error + that.r_error + r_error * that.r_error
  )

  def *(c:Int, x:Number) = new Number(c * value, a_error, a_error / c * value)

  def /(that:Number) = new Number(value / that.value,
                                        (abs(value) * that.r_error + abs(that.value) * r_error) /
                                          ((that.value - that.a_error) * abs(that.value)),
                                        (r_error + that.r_error) / (1 - that.r_error)
  )

  def isNaN:Boolean = value.isNaN

  override def toString = "%.3f(\u00b1%.4f)(1\u00b1%.4f)".format(
    new lang.Double(value), new lang.Double(abs(a_error)), new lang.Double(abs(r_error)))

}

object Number {
  implicit def int2number(i: Int) = new Number(i)
}

object ErrorEstimation {
  val a:Number = new Number(0.035, 0.001)
  val b:Number = new Number(7.05, 0.01)
  val c:Number = new Number(-2.76, 0.01)

  def sqrt(x: Number): Number = new Number(math.sqrt(x.value), x.a_error, x.a_error / math.sqrt(x.value))

  def f(a:Number, b:Number, c:Number):Number = {
      val num:Number =  a * b - (a * sqrt((3 * a - c) / (2 * b)))
      val den:Number = a * a - b * b
      val result:Number = num / den

      if (!result.isNaN) result
      else throw new IllegalArgumentException("numerator = %s\ndenominator = %s".format(num, den))
  }

  def main(args: Array[String]):Unit = try
    println("f(a,b,c) = %s".format(f(a, b, c)))
    catch {
      case e: IllegalArgumentException => println(e.getMessage)
    }
}